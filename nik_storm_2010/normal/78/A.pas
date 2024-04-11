Program A78;
Var S1,S2,S3 : String;
    K1,K2,K3 : LongInt;



Procedure Kol( S : String; Var K : LongInt );
Var D,i : LongInt;
 Begin

   K:=0;
   D:=Length( S );
   For i:=1 to D do
    If ( S[ i ]='a' ) or ( S[ i ]='e' ) or ( S[ i ]='i' ) or ( S[ i ]='o' ) or ( S[ i ]='u' ) then Inc( K );

 End;


BEGIN

  ReadLn( S1 );
  ReadLn( S2 );
  ReadLn( S3 );

  Kol( S1,K1 );
  Kol( S2,K2 );
  Kol( S3,K3 );

  If ( K1=5 ) and ( K2=7 ) and ( K3=5 ) then WriteLn( 'YES' )
                                        else WriteLn( 'NO' );

END.