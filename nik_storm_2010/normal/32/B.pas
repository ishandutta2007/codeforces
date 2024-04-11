Program storm;
Var s:string;
    i,d:longint;


Procedure Inputdata;
 Begin

   ReadLn( S );

 End;


BEGIN

  Inputdata;

  S:=S+' ';
  i:=1; d:=length( S );
  While i<d do
   Begin

     If (S[i]='-') and (S[i+1]='-') then begin Inc( i,2 ); write( 2 ); end;
     If (S[i]='-') and (S[i+1]='.') then begin Inc( i,2 ); write( 1 ); end;
     If (S[i]='.') then begin Inc(i,1); write( 0 ); end;

   End;

END.