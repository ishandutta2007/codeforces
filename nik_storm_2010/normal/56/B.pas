Program storm;
Var A:array[1..1010] of longint;
    N,l,r,Nom,Kol,K,Ch,i:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N );
   For i:=1 to N do Read( A[ i ] );

 End;


Procedure Outputdata( l,r:longint );
 Begin

   WriteLn( l,' ',r );
   Halt;

 End;


BEGIN

  Inputdata;

  i:=1; Kol:=0;
  While i<=N do
   Begin

     If A[ i ] <> i then
      Begin

        If Kol=1 then Outputdata( 0,0 );
        Inc( Kol ); Nom:=i; K:=0; Ch:=A[ i ];
        While A[ i ] <> Nom do
         Begin

           Inc( K );
           If A[ i ] <> Ch-K+1 then Outputdata( 0,0 );
           Inc( i );

         End;

        l:=Nom; r:=i;

      End;

     Inc( i );

   End;

  Outputdata( l,r );

END.