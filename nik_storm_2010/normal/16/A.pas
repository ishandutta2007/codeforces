Program storm;
Var A:array[-10..110,-10..110] of char;
    N,M:longint;
    i,j:longint;


Procedure Inputdata;
Var i:longint;
 Begin

   Readln( N,M );
   For i:=1 to N do
    Begin

      For j:=1 to M do Read( A[i,j] );
      ReadLn;

    End;

 End;


Procedure Outputdata(Priz:longint);
 Begin

   If Priz=1 then WriteLn( 'YES' )
             else WriteLn( 'NO' );

 End;


Function Control_1:boolean;
Var i:longint;
 Begin

   For i:=1 to N do
    If (A[i,1]=A[i+1,1]) or (A[i,1]=A[i-1,1]) then Exit( false );

   Exit( true );

 End;


Function Control_2:boolean;
Var i,j:longint;
 Begin

   For i:=1 to N do
    For j:=1 to M do
     If A[ i,1 ] <> A[ i,j ] then Exit( False );

   Exit( True );

 End;


BEGIN

  Inputdata;

  If (Control_1) and (Control_2) then Outputdata( 1 )
                                 else Outputdata( 0 );

END.