Program storm;
Var Kol,K:longint;


Procedure Inputdata;
Var S:string;
    i:longint;
 Begin

   While not(Eof) do
    Begin

      Readln( S );
      If S[1]='+' then Inc( Kol );
      If S[1]='-' then Dec( Kol );
      If (S[1]<>'-') and (S[1]<>'+') then
       Begin

         i:=1;
         While S[i]<>':' do Inc( i );
         If i>Length( S ) then
                          else K:=K+((Length(s)-i))*kol;

       End;

    End;

 End;


Procedure Outputdata;
 Begin

   WriteLn( K );

 End;


BEGIN

  K:=0;
  Inputdata;
  Outputdata;

END.