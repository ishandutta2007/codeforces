Program B90;
Const
  NMax = 100;
  MMax = 100;

Var A,B : Array[ 1..NMax,1..MMax ] of Char;
    N,M,i,j,i1,j1,Kol : LongInt;
    S : AnsiString;



BEGIN

  ReadLn( N,M );
  For i:=1 to N do
   Begin
     For j:=1 to M do Read( A[ i,j ] );
     ReadLn;
   End;

  B:=A;
  For i:=1 to N do
   For j:=1 to M do
     Begin

       Kol:=0;
       For i1:=i+1 to N do
        If A[ i,j ] = A[ i1,j ] then
         Begin
          Kol:=1;
          B[ i1,j ]:='.';
         End;

       For j1:=j+1 to M do
        If A[ i,j ] = A[ i,j1 ] then
         Begin
           Kol:=1;
           B[ i,j1 ]:='.';
         End;

       If Kol=1 then B[ i,j ]:='.';

     End;

  S:='';
  For i:=1 to N do
   For j:=1 to M do
    If B[ i,j ]<>'.' then S:=S+B[ i,j ];

  WriteLn( S );

END.