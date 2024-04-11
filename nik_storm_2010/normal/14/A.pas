Program storm;
Var A:array[1..100,1..100] of char;
    N,M:longint;
    i1,i2,j1,j2:longint;


Procedure Inputdata;
Var i,j:longint;
 Begin

   ReadLn( N,M );

   For i:=1 to N do
    Begin

      For j:=1 to M do Read( A[i,j] );
      ReadLn;

    End;

 End;


Procedure Outputdata;
Var i,j:longint;
 Begin

   For i:=i1 to i2 do
    Begin

      For j:=j1 to j2 do Write( A[i,j] );
      WriteLn;

    End;

 End;


Function Selection(i,j,Kof:longint):boolean;
Var s:longint;
 Begin

   Case Kof of
   1:
   Begin

     For s:=1 to N do
      If A[ s,j ]<>'.' then Exit( False );

     Exit( True );

   End;
   2:
   Begin

     For s:=j to M do
      If A[ i,s ]<>'.' then Exit( False );

     Exit( True );

   End;
 End;

 End;


BEGIN

  Inputdata;

  i1:=1;
  While Selection( i1,1,2 ) = True do Inc( i1 );

  i2:=N;
  While Selection( i2,1,2 ) = True do Dec( i2 );

  j1:=1;
  While Selection( 1,j1,1 ) = True do Inc( j1 );

  j2:=M;
  While Selection( 1,j2,1 ) = True do Dec( j2 );

  Outputdata;

END.