#include <SPI.h>
#include <MFRC522.h>
 
 
#define SS_PIN 10
#define RST_PIN 9
 
int elock = 4;    
 
MFRC522 mfrc522(SS_PIN, RST_PIN);
const int ledPin = 8;
void setup() {
      pinMode(ledPin, OUTPUT);
        Serial.begin(9600);        // Initialize serial communications with the PC
      pinMode(elock,OUTPUT);
      digitalWrite(elock, LOW);
        SPI.begin();                // Init SPI bus
        mfrc522.PCD_Init();        // Init MFRC522 card
        //Serial.println("Scan a MIFARE Classic PICC to demonstrate Value Blocks.");
       
}



  
 void loop() {
  
        // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
        MFRC522::MIFARE_Key key;
        for (byte i = 0; i < 6; i++) {
                key.keyByte[i] = 0xFF;
        }
        // Look for new cards
        if ( ! mfrc522.PICC_IsNewCardPresent()) {
                return;
        }
 
        // Select one of the cards
        if ( ! mfrc522.PICC_ReadCardSerial()) {
          
        
        
                return;
        }
        // Now a card is selected. The UID and SAK is in mfrc522.uid.
      
 
   int count=0;
        // defining Cards here 
//Card UID: 90 247 108 63   saloni
//Card UID: 90 07 70 63    shalini
//Card UID: 108 34 168 50  aditya
//Card UID: 220 19 116 50   dhruv
              
         if( (mfrc522.uid.uidByte[0] == 90) && (mfrc522.uid.uidByte[1] == 247) && (mfrc522.uid.uidByte[2] == 108) && (mfrc522.uid.uidByte[3] == 63) )
         {
          Serial.println("Card detected");
            // Dump UID
          Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.println(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.println(mfrc522.uid.uidByte[i], DEC);
               count=count+1;
        }
            
         }
          if( (mfrc522.uid.uidByte[0] == 90) && (mfrc522.uid.uidByte[1] == 07) && (mfrc522.uid.uidByte[2] == 70) && (mfrc522.uid.uidByte[3] == 63) )
           {
            Serial.println("Card detected");
            // Dump UID
          Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.println(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.println(mfrc522.uid.uidByte[i], DEC);
               count=count+1;
        }
       
         }
           if( (mfrc522.uid.uidByte[0] == 108) && (mfrc522.uid.uidByte[1] == 34) && (mfrc522.uid.uidByte[2] == 168) && (mfrc522.uid.uidByte[3] == 50) )
            {
              Serial.println("Card detected");
            // Dump UID
          Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.println(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.println(mfrc522.uid.uidByte[i], DEC);
               count=count+1;
        }
       
         }
            if( (mfrc522.uid.uidByte[0] == 220) && (mfrc522.uid.uidByte[1] == 19) && (mfrc522.uid.uidByte[2] == 116) && (mfrc522.uid.uidByte[3] == 50) )
             {
              Serial.println("Card detected");
            // Dump UID
          Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.println(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.println(mfrc522.uid.uidByte[i], DEC);
               count=count+1;
        } 
       
         }
          
  if (count % 2 == 0) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
  Serial.print("no of taps by this uid:");
  
      Serial.println(count);
        

        
  delay(1000);
       
}
