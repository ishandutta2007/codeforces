const
  lim=100000;
var
  f:array[0..lim] of extended;
  n,i:longint;
  ans,p:extended;

begin
  read(n);
  for i:=1 to n do
  begin
    read(p);
    ans:=ans+2*(f[i-1]*p)+p;
    f[i]:=(f[i-1]*p)+p;
  end;
  writeln(ans:0:6);
end.