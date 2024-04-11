Program A92;
Var N,M,i : LongInt;


Begin

  ReadLn( N,M );

  i:=1;
  While i<=M do
   Begin

     Dec( M,i );
     If i=N then i:=1
            else Inc( i );

   End;


  WriteLn( M );

End.