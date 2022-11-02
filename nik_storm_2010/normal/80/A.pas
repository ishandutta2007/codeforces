Program A80;
Var N,M : LongInt;



Function Prost( A : LongInt ) : Boolean;
Var i : LongInt;
 Begin

   If A=1 then Exit( False );

   For i:=2 to round( sqrt( A ) ) do
    If A mod i = 0 then Exit( False );

   Exit( True );

 End;


BEGIN

  ReadLn( N,M );

  Inc( N );
  While Prost( N )<>True do Inc( N );

  If N=M then WriteLn( 'YES' )
         else WriteLn( 'NO' );

END.