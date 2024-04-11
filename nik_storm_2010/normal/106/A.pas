Program A106;
Var
  s : string;
  m1,s1,m2,s2,c : char;
  i1,i2 : longint;



Procedure opoznat( sim:char; var ch:longint );
 Begin
  if sim='6' then ch:=1;
  if sim='7' then ch:=2;
  if sim='8' then ch:=3;
  if sim='9' then ch:=4;
  if sim='T' then ch:=5;
  if sim='J' then ch:=6;
  if sim='Q' then ch:=7;
  if sim='K' then ch:=8;
  if sim='A' then ch:=9;
 End;


BEGIN

  readln(c);
  readln(s);

  m1:=s[1]; s1:=s[2];
  m2:=s[4]; s2:=s[5];

  if (s1<>s2) and (s1<>c) and (s2<>c) then begin writeln('NO'); halt; end;
  if (s1=c)   and (s2<>c) then begin writeln('YES'); halt; end;
  if (s1<>c)  and (s2=c)  then begin writeln('NO'); halt; end;

  opoznat(m1,i1);
  opoznat(m2,i2);

  if i1>i2 then writeln('YES')
           else writeln('NO');

END.