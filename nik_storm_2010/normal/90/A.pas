Program A90;
Var R,G,B,Koef,Time : LongInt;



BEGIN

  ReadLn( R,G,B );

  Koef:=1; Time:=-1;
  While ( R>0 ) or ( G>0 ) or ( B>0 ) do
   Begin

     If Koef = 1 then Dec( R,2 );
     If Koef = 2 then Dec( G,2 );
     If Koef = 3 then Dec( B,2 );

     Inc( Time );
     Inc( Koef );
     If Koef = 4 then Koef:=1;

   End;

  Inc( Time,30 );
  WriteLn( Time );

END.