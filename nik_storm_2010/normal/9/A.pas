Program storm;
Uses Math;
Var Y,W,Ch1,Ch2,N:longint;


Procedure Inputdata;
 Begin

  Readln( Y,W );

 End;


Procedure Outputdata;
 Begin

   Writeln( Ch1,'/',Ch2 );

 End;


Procedure Nod(A,B:longint; var N:longint);
 Begin

   While (A<>0) and (B<>0) do

     If A>B then A:=A mod B
            else B:=B mod A;

   N:=A+B;

 End;


BEGIN

  Inputdata;

  Ch1:=6-max(Y,W)+1;
  Ch2:=6;
  Nod(Ch1,Ch2,N);
  Ch1:=Ch1 div N;
  Ch2:=Ch2 div N;

  Outputdata;

END.