Program storm;
Var S1,S2,S3,S:ansistring;
    Ot:array[1..1010] of string;
    N:longint;


Procedure Perem(S:ansistring; var S1:ansistring);
Var D:longint;
    i,o:longint;
 Begin

   i:=1; D:=Length( S ); S1:='';
   While i<=d do
    Begin

      O:=Ord( S[i] );
      If (S[i]<>'-') and (S[i]<>'_') and (S[i]<>';') then
       Begin

         If ( O>=65 ) and ( O<=90 ) then S1:=S1+Chr( O+32 )
                                    else S1:=S1+S[i];

       End;

      Inc( i );

    End;

 End;


Procedure Inputdata;
Var i,j:longint;
    St1,St2,St3,St4,St5,St6:ansistring;
 Begin

   ReadLn( S1 ); Perem( S1,S1 );
   ReadLn( S2 ); Perem( S2,S2 );
   ReadLn( S3 ); Perem( S3,S3 );
   St1:=S1+S2+S3; St2:=S1+S3+S2; St3:=S2+S1+S3;
   St4:=S2+S3+S1; St5:=S3+S1+S2; St6:=S3+S2+S1;

   ReadLn( N );
   For i:=1 to N do
    Begin

      ReadLn( S );
      Perem( S,S );
      If (S=St1) or (S=St2) or (S=St3) or (S=St4) or (S=St5) or (S=St6)
       then Ot[i]:='ACC'
       else Ot[i]:='WA';

    End;

 End;


Procedure Outputdata;
Var i:longint;
 Begin

   For i:=1 to N do WriteLn( Ot[i] );

 End;


BEGIN

  Inputdata;
  Outputdata;

END.