Program storm;
Var Priz1,Priz2,Priz3:extended;
    A,B,C,D,E,F:longint;
    KolGold,KolPlumbum,KolSand:extended;


Procedure Inputdata;
 Begin

   ReadLn( A,B,C,D,E,F );

 End;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;


BEGIN

  Inputdata;

  If ((A=0) and (B<>0) and (D<>0)) or ((C=0) and (D<>0)) or ((E=0) and (F<>0) and (B<>0) and (D<>0)) then Outputdata( 'Ron' );
  If (B=0) or (D=0) or (F=0) then Outputdata( 'Hermione' );

  KolGold:=F;

  Priz1:=E / D;

  KolPlumbum:=Priz1*C;

  Priz2:=KolPlumbum / B;

  KolSand:=Priz2*A;

  If KolSand >= KolGold then Outputdata( 'Hermione' )
                        else Outputdata( 'Ron' );

END.