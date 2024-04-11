Program storm;
Var Ot,Del:array[1..75] of int64;
    C,B,D,Clear:array[1..100] of longint;
    N,Kol,Ch,Kol1,Kol2,Chi,L,R,Gran:int64;
    i:longint;


Procedure Inputdata;
 Begin

   ReadLn( N );

 End;


Procedure Outputdata( Answer:longint );
Var i:longint;
 Begin

   If Answer=1 then begin WriteLn( -1 ); Halt; end;
   For i:=1 to N-1 do WriteLn( Ot[ i ] );
   For i:=Gran downto 1 do Write( C[ i ] );

 End;


Function Prost( Chiclo:longint ) : boolean;
Var i:longint;
 Begin

   Prost:=True;
   For i:=2 to round( sqrt( Chiclo ) ) do
    If Chiclo mod i = 0 then Exit( False );

 End;


Function Poisk : int64;
 Begin

   While Prost( Ch )<>True do Inc( Ch,2 );
   Poisk:=Ch; Inc( Ch,2 );

 End;


Procedure Dopoln;
Var i,Ost:longint;
 Begin

   i:=1; Ost:=0;
   While i<100 do
    Begin

      Inc( C[ i ],Ost );
      If C[ i ]>=10 then Ost:=C[ i ] div 10
                    else Ost:=0;
      C[ i ]:=C[ i ] mod 10;
      If C[ i ]<>0 then Gran:=i;
      Inc( i );

    End;

 End;


Procedure Sum( Ch:longint );
Var i,j,Kol:longint;
 Begin

   Kol:=0;
   While Ch<>0 do
    Begin

      Inc( Kol );
      D[ Kol ]:=Ch mod 10;
      Ch:=Ch div 10;

    End;

   B:=C;
   C:=Clear;
   For i:=1 to Kol do
    For j:=1 to Gran do
     C[ i+j-1 ]:=C[ i+j-1 ]+D[ i ]*B[ j ];

   Dopoln;

 End;


BEGIN

  Inputdata;
  Ch:=7;

  If N=2 then Outputdata( 1 );

  For i:=1 to N-1 do
   Begin

     Chi:=Poisk;
     Ot[ i ]:=2*Chi;
     Del[ i ]:=Chi;

   End;

  C[ 1 ]:=7; Gran:=1;
  For i:=2 to N-1 do Sum( Del[ i ] );

  Outputdata( 0 );

END.