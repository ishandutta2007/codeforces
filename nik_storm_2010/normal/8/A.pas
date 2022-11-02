Program storm;
Var S:ansistring;
    S1,S2,S3,S4:string;
    D,D1,D2,Priz1,Priz2,i:longint;


Procedure Inputdata;
 Begin

   ReadLn( S );
   ReadLn( S1 );
   ReadLn( S2 );

 End;


Procedure Outputdata( Answer:string );
 Begin

   WriteLn( Answer );
   Halt;

 End;


Function Prov1:longint;
Var i,Nom1,Nom2:longint;
    Sn:string;
 Begin

    Nom1:=0; Nom2:=0;
    For i:=1 to D-D1+1 do
     Begin

       Sn:=Copy( S,i,D1 );
       If Sn=S1 then Begin Nom1:=i+D1; Break; end;

     End;

     If Nom1=0 then Exit( 0 );

     For i:=Nom1 to D-D2+1 do
      Begin

        Sn:=Copy( S,i,D2 );
        If Sn=S2 then begin Nom2:=i+D2; Break; end;

      End;

     If Nom2=0then Exit( 0 );

     Exit( 1 );

 End;


Function Prov2:longint;
Var i,Nom1,Nom2:longint;
    Sn:string;
 Begin

    Nom1:=0; Nom2:=0;
    For i:=D downto D1 do
     Begin

       Sn:=Copy( S,i-D1+1,D1 );
       If Sn=S3 then Begin Nom1:=i-D1; Break; end;

     End;

     If Nom1=0 then Exit( 0 );

     For i:=Nom1 downto D2 do
      Begin

        Sn:=Copy( S,i-D2+1,D2 );
        If Sn=S4 then begin Exit( 1 ); Break; end;

      End;

     Exit( 0 );

 End;


BEGIN

  Inputdata;

  D:=Length( S ); D1:=Length( S1 ); D2:=Length( S2 );
  S3:=''; S4:='';
  For i:=1 to D1 do S3:=S3+S1[ D1-i+1 ];
  For i:=1 to D2 do S4:=S4+S2[ D2-i+1 ];
  Priz1:=Prov1;
  Priz2:=Prov2;

  If ( Priz1=1 ) and ( Priz2=1 ) then Outputdata( 'both' );
  If ( Priz1=1 ) and ( Priz2=0 ) then Outputdata( 'forward' );
  If ( Priz1=0 ) and ( Priz2=1 ) then Outputdata( 'backward' );

  Outputdata( 'fantasy' );

END.