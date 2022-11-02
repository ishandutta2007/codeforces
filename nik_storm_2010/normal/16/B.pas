Program storm;
Var A,B:array[ 1..50 ] of longint;
    N,M,Kol,K,i:int64;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N,M );
   For i:=1 to M do ReadLn( A[ i ],B[ i ] );

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


Procedure Qsort( l,r:int64 );
Var i,j,D,W:int64;
 Begin

   i:=l; j:=r;
   D:=B[ (i+j) div 2 ];
   While i<=j do
    Begin

      While B[ i ]<D do Inc( i );
      While B[ j ]>D do Dec( j );
      If i<=j then
       Begin

         W:=A[ i ]; A[ i ]:=A[ j ]; A[ j ]:=W;
         W:=B[ i ]; B[ i ]:=B[ j ]; B[ j ]:=W;
         Inc( i ); Dec( j );

       End;

    End;

   If i<r then Qsort( i,r );
   If l<j then Qsort( l,j );

 End;


BEGIN

  Inputdata;

  Qsort( 1,M );
  K:=0; i:=M; Kol:=0;
  While (K<N) and (i>=1) do
   Begin

     If K+A[ i ] <= N then begin Inc( K,A[ i ] ); Inc( Kol,B[ i ]*A[ i ] ); end
                      else begin Inc( Kol,(N-K) * B[ i ] ); Inc( K,N-K );  end;
     Dec( i );

   End;

  Outputdata;

END.