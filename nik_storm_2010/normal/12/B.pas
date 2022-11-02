Program storm;
Var A,B,C:array[ 0..15 ] of longint;
    D:array[ 0..9 ] of longint;
    N,M,Kol1,Kol2,Kol,Nom,i,N1,M1:longint;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;



Procedure Inputdata;
Var i,Code:longint;
    S:string;
 Begin

   Kol1:=0;
   ReadLn( N );
   N1:=N;

   While N<>0 do
    Begin

       Inc( Kol1 );
       A[ Kol1 ]:=N mod 10;
       N:=N div 10;

    End;

   Kol2:=0;
   ReadLn( S );
   Val( S,M,Code );
   If ( M=0 ) and ( Length( S )=1 ) and ( A[ 1 ]=0 ) then Outputdata( 'OK' );
   If ( M=0 ) and ( Length( S )<>1 ) then Outputdata( 'WRONG_ANSWER' );
   M1:=M;

   While M<>0 do
    Begin

      Inc( Kol2 );
      B[ Kol2 ]:=M mod 10;
      M:=M div 10;

    End;

   If ( Kol2<>Length( S )) then Outputdata( 'WRONG_ANSWER' );
   If ( B[ Kol2 ]=0 ) and ( M1<>0 ) then Outputdata( 'WRONG_ANSWER' );

 End;


Procedure Qsort( l,r:longint );
Var i,j,D,W:longint;
 Begin

   i:=l; j:=r;
   D:=A[ (i+j) div 2 ];
   While i<=j do
    Begin

      While A[ i ]<D do Inc( i );
      While A[ j ]>D do Dec( j );
      If i<=j then
       Begin

         W:=A[ i ]; A[ i ]:=A[ j ]; A[ j ]:=W;
         Inc( i ); Dec( j );

       End;

    End;

   If i<r then Qsort( i,r );
   If l<j then Qsort( l,j );

 End;


BEGIN

  Inputdata;

  If ( A[ 1 ]=0 ) and ( B[ 1 ] = 0 ) and ( Kol1=Kol2 ) and ( Kol1=1 ) then Outputdata( 'OK' );
  If ( N1=0 ) and ( M1=0 ) then Outputdata( 'OK' );
  If ( N1=0 ) or ( M1=0 ) then Outputdata( 'WRONG_ANSWER' );
  If Kol1<>Kol2 then Outputdata( 'WRONG_ANSWER' );

  Qsort( 1,Kol1 );
  For i:=1 to Kol1 do
   If A[ i ]<>0 then begin Nom:=i; Break; end;

  If Nom<> 1 then
   Begin

     A[ 1 ]:=A[ Nom ]; A[ Nom ]:=0;

   End;

  For i:=1 to Kol1 do
   If A[ i ] <> B[ Kol1-i+1 ] then Outputdata( 'WRONG_ANSWER' );

  Outputdata( 'OK' );

END.