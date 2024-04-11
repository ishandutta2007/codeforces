Program storm;
Var A:array[1..5] of longint;
    Nom,i:longint;
    f:text;


Procedure Inputdata;
Var i,N1,N2,Tmp:longint;
 Begin

   Assign( f,'input.txt' ); ReSet( f );
   ReadLn( f,Nom );
   For i:=1 to 3 do A[ i ]:=i;

   For i:=1 to 3 do
    Begin

      ReadLn( f,N1,N2 );
      Tmp:=A[ N1 ]; A[ N1 ]:=A[ N2 ]; A[ N2 ]:=Tmp;

    End;

   Close( f );

 End;


Procedure Outputdata( Answer:longint );
 Begin

   Assign( f,'output.txt' ); ReWrite( f );
   WriteLn( f,Answer );
   Close( f );
   Halt;

 End;


BEGIN

  Inputdata;

  For i:=1 to 3 do
   If A[ i ] = Nom then Outputdata( i );

END.