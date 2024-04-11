Program storm;
Const Size = 110;
Var   Answer:array[ 1..Size ] of longint;
      P,N,K,T,Koef,R,i:longint;


Procedure Inputdata;
 Begin

   ReadLn( N,K,T );

 End;


Procedure Outputdata;
Var i:longint;
 Begin

   For i:=1 to N do Write( Answer[ i ],' ' );

 End;


BEGIN

  Inputdata;

  Koef:=N*K;
  P:=Trunc( Koef/100*T );
  R:=P div K;
  For i:=1 to R do Answer[ i ]:=K;
  Answer[ R+1 ]:=P-( R*K );

  Outputdata;

END.