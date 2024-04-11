var
n,m:longint;
x:int64;
i:longint;

begin
readln(n);
readln(m);
x:=n;
while x<m do
begin
  x:=x*n;
  inc(i);
end;
if x=m then
begin
  writeln('YES');
  writeln(i);
end
else
  writeln('NO');
end.