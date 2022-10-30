Program storm;
Var A:array[ 1..100,1..100 ] of integer;
    N,M,K,MinKol,i,j,X,Y:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   ReadLn( N,M );
   For i:=1 to N do
    Begin

      For j:=1 to M do Read( A[ i,j ] );
      ReadLn;

    End;

   ReadLn( X,Y );

 End;


Procedure Outputdata;
 Begin

   WriteLn( MinKol );

 End;


Procedure Ko( i,j:longint; Var Kol:longint );
Var k1,k2:longint;
 Begin

   Kol:=0;
   For k1:=i to i+X-1 do
    For k2:=j to j+Y-1 do
     If A[ k1,k2 ] = 1 then Inc( Kol );

 End;

Procedure Ko1( i,j:longint; Var Kol1:longint );
Var k1,k2:longint;
 Begin

   Kol1:=0;
   For k1:=i to i+Y-1 do
    For k2:=j to j+X-1 do
     If A[ k1,k2 ] = 1 then Inc( Kol1 );

 End;


BEGIN

  Inputdata;

  MinKol:=MaxLongint;
  For i:=1 to N-X+1 do
   For j:=1 to M-Y+1 do
    Begin

      Ko( i,j,K );
      If K < MinKol then MinKol:=K

    End;

  For i:=1 to N-Y+1 do
   For j:=1 to M-X+1 do
    Begin

      Ko1( i,j,K );
      If K < MinKol then MinKol:=K

    End;

  Outputdata;

END.