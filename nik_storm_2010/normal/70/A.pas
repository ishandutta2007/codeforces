Program storm;
Var Sum:int64;
    i,N:longint;


Procedure Inputdata;
 Begin

   ReadLn( N );

 End;


Procedure Outputdata( Answer:int64 );
 Begin

   WriteLn( Answer );
   Halt;

 End;


Procedure Step1( Chiclo,St:longint; Var Step:int64 );
Var i:longint;
 Begin

   Step:=1;
   For i:=1 to St do Step:=Step*Chiclo mod 1000003;

 End;


BEGIN

  Inputdata;

  Step1( 3,N-1,Sum );

  Outputdata( Sum );

END.