Program storm;
Var A:array[-1010..1010] of integer;
    S:ansistring;
    D:longint;




Procedure Inputdata;
Var i1,i2,Ch,Code:longint;
    S1:ansistring;
 Begin

   ReadLn( S );
   i1:=1; i2:=1; D:=Length( S );
   S:=S+'             ';
   While i2<=D do
    Begin

      While ( S[i2]<>',' ) and ( i2<=D ) do Inc( i2 );
      S1:=Copy( S,i1,i2-i1 );
      Val( S1,Ch,Code );
      A[ Ch ]:=1;
      i1:=i2+1;
      Inc( i2 );

    End;

 End;


Procedure Outputdata;
Var S:ansistring;
    S1,S2:string;
    i,Nach,Endd:longint;
 Begin

   i:=0; S:='';
   While i<=1010 do
    If A[ i ] = 1 then
     Begin

       Nach:=i;
       While A[ i ] = 1 do Inc( i );
       Endd:=i-1;
       Str( Nach,S1 ); Str( Endd,S2 );

       If Nach=Endd then S:=S+ S1 + ','
                    else S:=S+ S1 + '-' + S2 + ',';

     End
                  else Inc( i );

   Delete( S,Length( S ),1 );
   WriteLn( S );

 End;


BEGIN

  Inputdata;
  Outputdata;

END.