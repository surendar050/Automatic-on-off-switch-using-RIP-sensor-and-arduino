#include <Arduino.h>

int sensorPin = 2;    
int relayPin = 8;     
int sensorValue = 0;  

unsigned long lastMotionTime = 0;   
unsigned long delayTime = 5000;     

void setup() {
  pinMode(sensorPin, INPUT);   
  pinMode(relayPin, OUTPUT);   
  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}

void loop() {
  sensorValue = digitalRead(sensorPin); 

  if (sensorValue == HIGH) {  
    digitalWrite(relayPin, HIGH);     lastMotionTime = millis();    
    Serial.println("Motion Detected - Device ON");
  }

  if ((millis() - lastMotionTime) > delayTime) {
    digitalWrite(relayPin, LOW); // Turn OFF device
    Serial.println("No Motion - Device OFF");
  }
}
