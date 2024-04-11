uses
  math;
const
  ll=5000;
var
  f:array[1..ll,0..1] of longint;
  a,b,c:array[1..ll] of longint;
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do read(c[i]);
  f[1,0]:=b[1];
  f[1,1]:=a[1];
  for i:=2 to n do
  begin
    f[i,0]:=max(f[i-1,0]+b[i],f[i-1,1]+c[i]);
    f[i,1]:=max(f[i-1,0]+a[i],f[i-1,1]+b[i]);
  end;
  writeln(f[n,1]);
end.