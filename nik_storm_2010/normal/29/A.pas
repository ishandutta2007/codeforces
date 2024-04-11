Program storm;
Var X, D:array[1..100] of longint;
    N:longint;
    i,j:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   Readln( N );
   For i:=1 to n do Readln( X[i],D[i] );

 End;


Procedure Outputdata(Ch:string);
 Begin

   Writeln( Ch );

 End;


BEGIN

  Inputdata;

  For i:=1 to n do
   For j:=i+1 to n do

     If (X[i]+D[i]=X[j]) and (X[j]+D[j]=X[i]) then
      Begin

        Outputdata('YES');
        Halt;

      End;

  Outputdata('NO');

END.