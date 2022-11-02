const
  ll=3000;
var
  f:array[0..ll*ll] of int64;
  a:array[0..ll] of longint;
  n,cur,i,j:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  cur:=0;
  for i:=1 to n do for j:=i+1 to n do if (a[i]>a[j]) then inc(cur);
  f[0]:=0;
  f[1]:=1;
  for i:=2 to cur do f[i]:=f[i-2]+4;
  writeln(f[cur]);
end.