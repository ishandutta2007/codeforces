Program A81;
Var S : AnsiString;
    i : LongInt;



Begin

  ReadLn( S );

  For i:=Length( S ) downto 2 do
   If S[ i ]=S[ i-1 ] then Delete( S,i-1,2 );

  WriteLn( S );

End.