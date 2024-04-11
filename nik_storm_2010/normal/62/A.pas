Program storm;
Var Al,Ar,Bl,Br,Kof:longint;


Procedure Inputdata;
 Begin

   ReadLn( Al,Ar );
   ReadLn( Bl,Br );

 End;


Procedure Outputdata(Priz:longint);
 Begin

   If Priz=1 then WriteLn( 'YES' )
             else WriteLn( 'NO' );

 End;


BEGIN

  Inputdata;

  If (((Al-Br>=0) and (Al-Br<=1)) or ((Br-Al>=0) and (Br-Al<=(3+(Al-1)*2))))
   or (((Bl-Ar>=0) and  (Bl-Ar<=(3+(Ar-1)*2))) or ((Ar-Bl>=0) and (Ar-Bl<=1)))
    then Outputdata( 1 )
    else Outputdata( 0 );

END.