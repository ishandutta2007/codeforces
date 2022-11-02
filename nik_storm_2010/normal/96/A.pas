Program A96;
Var S : String;
    D,i,Kol : Longint;
    Ch : Char;



BEGIN

  ReadLn( S );
  D:=Length( S );

  Ch:=S[ 1 ]; Kol:=1; i:=2;
  While i<=D do
   Begin
     If S[ i ] = Ch then Inc( Kol )
                    else Begin Ch:=S[ i ]; Kol:=1; End;

     If Kol = 7 then Begin WriteLn( 'YES' ); Halt; end;
     Inc( i );

   End;

  WriteLn( 'NO' );

END.