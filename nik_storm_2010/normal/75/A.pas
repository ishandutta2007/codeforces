Program A75;
Var A,B,C,Code    : LongInt;
    S1,S2,S3,SAns : String;



Procedure KillZero( S : String; Var S1 : String );
Var D,i : LongInt;
 Begin

   D:=Length( S );
   i:=1;
   While i<=D do
    Begin

      If S[ i ] = '0' then begin Delete( S,i,1 ); Dec( D ); end
                      else Inc( i );

    End;

   S1:=S;

 End;


BEGIN

  ReadLn( A );
  ReadLn( B );
  C:=A+B;

  Str( A,S1 );
  Str( B,S2 );
  Str( C,S3 );

  KillZero( S1,SAns ); Val( SAns,A,Code );
  KillZero( S2,SAns ); Val( SAns,B,Code );
  KillZero( S3,SAns ); Val( SAns,C,Code );

  If A + B = C then WriteLn( 'YES' )
               else WriteLn( 'NO' );

END.