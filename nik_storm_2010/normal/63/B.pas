Program storm;
Var A:array[1..150] of longint;
    i,j,j1:longint;
    N,K,Kol:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N,K );
   For i:=1 to N do Read( A[i] );

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


BEGIN

  Inputdata;

  Kol:=0;
  While A[1]<K do
   Begin

     Inc( Kol );
     j:=1;
     While j<=N do
      Begin

        j1:=j;
        While A[j]=A[j1] do inc(j);
        Inc( A[j-1] );

      End;

   End;
  Outputdata;

END.