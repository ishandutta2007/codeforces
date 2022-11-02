Program storm;
Var
	A:array[1..4,0..1010] of longint;
	Zap:array[ 1..5] of longint;
	Kof,Chisto:array[1..5] of longint;
	i,N,j,ChPred,Min,i1:longint;

Function Chiclo( i:longint ) : longint;
Begin
	Chiclo:=A[ 1,i ]*1000+A[ 2,i ]*100+A[ 3,i ]*10+A[ 4,i ];
End;

Procedure Inputdata;
Var
	i,Ch:longint;
Begin
	ReadLn( N );
	For i:=1 to N do
		Begin
			Read( Ch );
			A[ 1,i ]:=Ch div 1000;
			A[ 2,i ]:=Ch mod 1000 div 100;
			A[ 3,i ]:=Ch mod 100 div 10;
			A[ 4,i ]:=Ch mod 10;
		End;
End;

Procedure Outputdata( Priz:longint );
Var
	i:longint;
Begin
	If Priz=1 then begin WriteLn( 'No solution' ); Halt; end;
	For i:=1 to N do WriteLn( A[ 1,i ]*1000+A[ 2,i ]*100+A[ 3,i ]*10+A[ 4,i ] );
End;

Function Prov( i1,i2:longint ) : boolean;
Var
	i:longint;
Begin
	Prov:=True;
	For i:=1 to 4 do
		Begin
			If A[ i,i1 ] > A[ i,i2 ] then begin Prov:=False; Break; end;
			If A[ i,i1 ] < A[ i,i2 ] then begin Prov:=True; Break; end;
		End;
End;

BEGIN
	Inputdata;
	For i:=1 to 4 do Chisto[ i ]:=MaxLongint;
	A[ 1,0 ]:=1; A[ 2,0 ]:=0;	A[ 3,0 ]:=0; A[ 4,0 ]:=0;

	For i:=1 to N do
		Begin
			ChPred:=Chiclo( i-1 );
			Kof:=Chisto;
			For j:=1 to 4 do Zap[ j ]:=A[ j,i ];
			For i1:=1 to 4 do
                                begin
                                        For j:=0 to 9 do
				                Begin
						        A[ i1,i ]:=j;
                                                        If Prov( i-1,i ) = True then begin Kof[ i1 ]:=Chiclo( i ); Break; end;
					        End;
                                        A[ i1,i ]:=Zap[ i1 ];
                                end;
			Min:=MaxLongint;

			For j:=1 to 4 do If Kof[ j ]<Min then Min:=Kof[ j ];
			If Min = MaxLongint then Outputdata( 1 );
			If ( Min>=1000 ) and ( Min<=2011 ) and ( Min>=ChPred ) then else Outputdata( 1 );
			A[ 1,i ]:=Min div 1000;
			A[ 2,i ]:=Min div 100 mod 10;
			A[ 3,i ]:=Min div 10 mod 10;
			A[ 4,i ]:=Min mod 10;
		End;
	Outputdata( 0 );
END.