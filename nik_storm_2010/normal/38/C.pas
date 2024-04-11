Program storm;
Var A:array[1..150] of longint;
    Kol,K,N,L,Max:longint;
    i,j:longint;



Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N,L ); Max:=0;
   For i:=1 to N do begin Read( A[i] ); If A[i]>Max then Max:=A[i]; end;

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


BEGIN

  Inputdata;

  Kol:=0; i:=l;
  While i<=Max do
   Begin

     K:=0;
     For j:=1 to N do Inc( K,A[j] div i );
     If K*i>Kol then Kol:=K*i;
     Inc( i );

   End;

  Outputdata;

END.