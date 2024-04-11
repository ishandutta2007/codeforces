Program storm;
Var A:array[1..500] of longint;
    Kol,Sled,i,N,K,C,Ch:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N,K );
   Read( C );

   For i:=1 to C do
    Begin

      Read( Ch );
      A[ Ch ] :=1;

    End;

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


BEGIN

  Inputdata;

  Kol:=0; Sled:=K;
  For i:=1 to N do
   If ( i=Sled ) or ( A[ i ]=1 ) then begin Inc( Kol ); Sled:=i+K; end;

  Outputdata;

END.