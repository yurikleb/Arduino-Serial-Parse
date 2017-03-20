//Rescive Data From Serial + parse to control RGB LED Strip
//Sample Serial input: "255,255,255" to light the strip full white 


int rPin = 5; 
int gPin = 6; 
int bPin = 3;
char commandEnd  = '\n';
String command;

void setup() {
  pinMode(rPin, OUTPUT); // Set pin as OUTPUT
  pinMode(gPin, OUTPUT); // Set pin as OUTPUT
  pinMode(bPin, OUTPUT); // Set pin as OUTPUT 
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  if (Serial.available()) 
  { // If data is available to read,
    command = Serial.readStringUntil(commandEndS);
    //command.trim();
    parseCommand(command);
  }
  delay(10); // Wait 10 milliseconds for next reading
}

void parseCommand(String comm)
{
  //Parse String to Array
  String tmpStr = "";
  int commaIndex = 0;
  int nextValIndex = 0;
  int i = 0;
  int vals[3]={0,0,0};
  
  while (commaIndex > -1)
  {
    if(comm.indexOf(',', commaIndex+1) > -1)
      tmpStr = comm.substring(nextValIndex, comm.indexOf(',', commaIndex+1));
    else
      tmpStr = comm.substring(nextValIndex, comm.indexOf(NULL));
                
    vals[i] = tmpStr.toInt();
    i++;
    commaIndex = comm.indexOf(',', commaIndex+1);
    nextValIndex = commaIndex + 1;   
  } 
    
  //int val = comm.toInt(); 
  analogWrite(rPin, vals[0]);
  //Serial.println(vals[0]);
  analogWrite(gPin, vals[1]);
  //Serial.println(vals[1]);  
  analogWrite(bPin, vals[2]);
  //Serial.println(vals[2]);
  
}

