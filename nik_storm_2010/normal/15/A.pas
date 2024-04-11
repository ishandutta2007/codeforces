Program storm;
Var A,X:array[1..1200] of longint;
    N,T,Kol,i:longint;


Procedure Inputdata;
Var i:longint;
 Begin

    ReadLn( N,T );
    For i:=1 to N do Read( X[ i ],A[ i ] );

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


Procedure Qsort( l,r:longint );
Var i,j,D,W:longint;
 Begin

   i:=l; j:=r;
   D:=X[ (i+j) div 2 ];
   While i<=j do
    Begin

      While X[ i ] < D do Inc( i );
      While X[ j ] > D do Dec( j );
      If i<=j then
       Begin

         W:=A[ i ]; A[ i ]:=A[ j ]; A[ j ]:=W;
         W:=X[ i ]; X[ i ]:=X[ j ]; X[ j ]:=W;
         Inc( i ); Dec( j );

       End;

    End;

   If i<r then Qsort( i,r );
   If l<j then Qsort( l,j );

 End;


BEGIN

  Inputdata;

  Kol:=2;
  Qsort( 1,N );
  For i:=1 to N-1 do
   Begin

     If ((Abs( X[ i ]-X[ i+1 ] )) - ((A[ i ] / 2)+(A[ i+1 ] / 2))) = T then Inc( Kol,1 );
     If ((Abs( X[ i ]-X[ i+1 ] )) - ((A[ i ] / 2)+(A[ i+1 ] / 2))) > T then Inc( Kol,2 );

   End;

  Outputdata;

END.