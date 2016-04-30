/*# define trigpin 2
# define echopin 3

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

  
  // put your setup code here, to run once:

}

void loop() {
  double duration,distance,val=0.0;
  //digitalWrite(led,HIGH);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin,HIGH);
   delayMicroseconds(10);
  duration=pulseIn(echopin,HIGH, 50000);
  distance=(duration*0.034)/2;
  delay(100);
   val=digitalRead(trigpin);
    //digitalWrite(led,val);
    delay(100);
if ((distance>1)&&(distance<10))
{
    Serial.println("in range");
  Serial.print(distance);
  Serial.println("cm"); 
  Serial.println(duration);
  Serial.println(val);
   delay(300);
}
else
{
  Serial.println("invalid");
  
}
  // put your main code here, to run repeatedly:

}*/
# define trigpin 2
# define echopin 3
# define led 9

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(led, OUTPUT);

  
  // put your setup code here, to run once:

}

void loop() {
  double duration,distance,val;
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(3);
  digitalWrite(trigpin,HIGH);
   delayMicroseconds(1);
  duration=pulseIn(echopin,HIGH, 50000);
  distance=(duration*0.034)/2;

  
  if (distance>=10)
  {

    Serial.println("out of range");
    Serial.println("the cart is derailed");
  }
   else if ((distance<=10)&&(distance>=1))
  {
         if( (duration>=75)&&(duration<=130))
        {
      Serial.println("THE TRACK IS OKAY"); 
      digitalWrite(led,LOW);
      delay(1);
         }
     else if (duration>130)
    {
      
     val=digitalRead(trigpin);
    
    delay(1);
    
    Serial.println("in range");
  Serial.print(distance);
  Serial.println("cm");
  Serial.println(duration);
  digitalWrite(led,duration);
  delay(50);
  Serial.println("DANGER! THERE IS A FAULT");
   delay(1);//to delay the restarting of the loop
   
   //exit();
       }
  else
  {
   // goto distance;
    Serial.print(distance);
  }
  }
  /*else
  {
    Serial.print("invalid");
    delay(100);
    
  }*/

  // put your main code here, to run repeatedly:



}
