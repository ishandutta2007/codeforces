Program A110;
Var
  s,skol,answer : string;
  kol,i,d : longint;



Procedure prov( skol:string; var answer:string );
Var i : longint;
 Begin
  answer:='NO';
  for i:=1 to length(skol) do
   if (skol[i]<>'4') and (skol[i]<>'7') then exit;
  answer:='YES';
 End;


BEGIN

  readln(s);

  for i:=1 to length(s) do
   begin
    if s[i]='4' then inc(kol);
    if s[i]='7' then inc(kol);
   end;

  str(kol,skol);
  prov(skol,answer);

  writeln(answer);

END.