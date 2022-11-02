uses
  math;
const
  lim=100000;
var
  f:array[-lim..lim] of longint;
  a,b:array[1..lim] of longint;
  bal,n,k,i,j:longint;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do begin read(b[i]); b[i]:=b[i]*k; end;
  for i:=1 to n do
  begin
    bal:=a[i]-b[i];
    if (bal>0) then for j:=lim downto -lim do if (f[j]<>0) then f[j+bal]:=max(f[j+bal],f[j]+a[i]);
    if (bal<=0) then for j:=-lim to lim do if (f[j]<>0) then f[j+bal]:=max(f[j+bal],f[j]+a[i]);
    f[bal]:=max(f[bal],a[i]);
  end;
  if (f[0]=0) then writeln(-1) else writeln(f[0]);
end.