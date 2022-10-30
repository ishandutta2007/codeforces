Program storm;
Uses Math;
Var S,Answer:string;
    D,N:longint;


Procedure Inputdata;
Var i:longint;
    S1,Sp:string;
 Begin

   ReadLn( S );
   D:=Length( S );

   ReadLn( N );
   Answer:='';
   For i:=1 to N do
    Begin

      ReadLn( S1 );
      Sp:=Copy( S1,1,Min( D,Length( S1 ) ) );

      If ( Answer='' ) and ( Sp=S ) then Answer:=S1;
      If ( Sp=S ) and ( S1<Answer ) then Answer:=S1;

    End;


 End;


Procedure Outputdata;
 Begin

   If Answer='' then WriteLn( S )
                else WriteLn( Answer );

 End;


BEGIN

  Inputdata;
  Outputdata;

END.