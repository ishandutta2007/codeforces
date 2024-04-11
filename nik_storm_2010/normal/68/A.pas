Program storm;
Var P:array[1..5] of longint;
    A,B,Kol:int64;
    i:longint;


Procedure Inputdata;
 Begin

   ReadLn( P[ 1 ],P[ 2 ],P[ 3 ],P[ 4 ],A,B );

 End;


Procedure Outputdata;
 Begin

   WriteLn( Kol );

 End;


Function Prov( Chiclo:longint ) : boolean;
Var i1,i2,i3,i4,K:longint;
 Begin

   K:=0;
   For i1:=1 to 4 do
    For i2:=1 to 4 do
     For i3:=1 to 4 do
      For i4:=1 to 4 do
       If (i1<>i2) and (i1<>i3) and (i1<>i4) and (i2<>i3) and (i2<>i4) and (i3<>i4) and
           (Chiclo mod P[ i1 ] mod P[ i2 ] mod P[ i3 ] mod P[ i4 ] = Chiclo)
            then Inc( K );

   If K>=7 then Prov:=True
           else Prov:=False;

 End;


BEGIN

  Inputdata;

  Kol:=0;
  For i:=A to B do
   If Prov( i ) = True then Inc( Kol );

  Outputdata;

END.