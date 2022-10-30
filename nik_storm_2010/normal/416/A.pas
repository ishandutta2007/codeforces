uses
  math;
var
  n,left,right,i,x:longint;
  c1,c2,c3:char;
  s:shortstring;

procedure bad;
begin
  writeln('Impossible');
  halt;
end;

begin
  readln(n);
  left:=-2000000000;
  right:=+2000000000;
  for i:=1 to n do
  begin
    read(c1);
    read(c2);
    if (c2<>' ') then read(c3);
    read(x);
    read(c3);
    readln(c3);
    s:=c1+c2;
    if (c3='N') then
    begin
      if (s='> ') then s:='<=' else
      if (s='< ') then s:='>=' else
      if (s='>=') then s:='< ' else
      if (s='<=') then s:='> ';
    end;
    if (s='> ') then left:=max(left,x+1);
    if (s='< ') then right:=min(right,x-1);
    if (s='>=') then left:=max(left,x);
    if (s='<=') then right:=min(right,x);
    if (left<=right) then else bad;
  end;
  writeln(left);
end.