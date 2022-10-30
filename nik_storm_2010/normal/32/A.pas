Program storm;
Var A:array[1..1010] of longint;
    Kol,N,D:longint;
    i,j:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   Readln( N,D );

   For i:=1 to N do Read( A[i] );

 End;


Procedure Outputdata;
 Begin

   Writeln( Kol );

 End;


BEGIN

  Inputdata;

  Kol:=0;
  For i:=1 to n do
   For j:=i+1 to n do
    If Abs( A[i]-A[j] ) <= D then inc( Kol,2 );

  Outputdata;

END.