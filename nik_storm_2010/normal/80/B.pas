Program B80;
Var HH,MM,Grad2 : LongInt;
    Grad1 : Real;
    S : String;


Procedure Rash( S : String; Var A,B : LongInt );
Var S1,S2 : String;
    Code : LongInt;
 Begin

   S1:=S[ 1 ]+S[ 2 ];
   S2:=S[ 4 ]+S[ 5 ];

   Val( S1,A,Code );
   Val( S2,B,Code );

 End;


BEGIN

  ReadLn( S );
  Rash( S,HH,MM );

  If HH = 12 then HH:=0;
  If HH > 12 then HH:=HH-12;

  Grad1:=HH*30+MM*0.5;
  Grad2:=MM*6;

  WriteLn( Grad1:1:1,' ',Grad2 );

END.