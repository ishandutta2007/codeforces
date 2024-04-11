Program storm;
Var A,Ot:array[1..100010] of string;
    B:array[1..100010] of longint;
    Kol,No,N:longint;
    S:string;





Procedure Poisk( S:string; var Nom:longint );
Var i:longint;
 Begin

   Nom:=-1;
   For i:=1 to No do
    If S=A[ i ] then begin Nom:=i; Break; end;

 End;


Procedure Inputdata;
Var i,Nom,Nom1,Ch:longint;
    S1:ansistring;
 Begin

   Kol:=0; No:=0;
   ReadLn( N );
   For i:=1 to N do
    Begin

      ReadLn( S );
      Poisk( S,Nom );
      If Nom = -1 then Begin Inc( No ); A[ No ]:=S; Inc( Kol ); Ot[ Kol ]:='OK'; End
                  else Begin Inc( B[ Nom ] ); Str( B[ Nom ],S1 ); Inc( Kol ); Ot[ Kol ]:=S+S1; End;

    End;

 End;


Procedure Outputdata;
Var i:longint;
 Begin

   For i:=1 to Kol do WriteLn( Ot[ i ] );

 End;


BEGIN

  Inputdata;
  Outputdata;

END.