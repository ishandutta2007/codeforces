var
  s:ansistring;
  c1,c2,a:int64;
  d,i,nom,x,code:longint;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do if (s[i]='^') then nom:=i;
  c1:=0; c2:=0;
  for i:=1 to d do
  begin
    x:=nom-i;
    if (x=0) then break;
    if (s[x]='=') then continue;
    val(s[x],a,code);
    c1:=c1+a*i;
  end;
  for i:=1 to d do
  begin
    x:=nom+i;
    if (x>d) then break;
    if (s[x]='=') then continue;
    val(s[x],a,code);
    c2:=c2+a*i;
  end;
  if (c1=c2) then writeln('balance');
  if (c1>c2) then writeln('left');
  if (c1<c2) then writeln('right');
end.