uses
  math;
const
  lim=200;
var
  a,b:array[1..lim] of int64;
  f:array[0..lim,0..lim] of int64;
  good:array[1..lim] of boolean;
  q:array[1..2,1..1000000] of longint;
  n,m,i,x,j,nom,mn,l,r,st,en:longint;
  ans,help:int64;

procedure update(i,j:longint;x:int64);
begin
  if (f[i,j]>=x) then exit;
  if (f[i,j]=-1) then
  begin
    q[1,en]:=i;
    q[2,en]:=j;
    inc(en);
  end;
  f[i,j]:=x;
end;

begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to m do
  begin
    read(x);
    good[x]:=true;
  end;
  m:=0;
  ans:=0;
  for i:=1 to n do if (good[i]=false) then ans:=ans+a[i] else
  begin
    inc(m);
    b[m]:=a[i];
  end;
  for i:=1 to m do for j:=i+1 to m do if (b[i]>b[j]) then
  begin
    help:=b[i];
    b[i]:=b[j];
    b[j]:=help;
  end;
  for i:=0 to m+1 do for j:=0 to m+1 do f[i,j]:=-1;
  st:=1; en:=1;
  update(1,m,ans);
  while (st<>en) do
  begin
    l:=q[1,st];
    r:=q[2,st];
    inc(st);
    if (l>r) then continue;
    if (f[l,r]>=b[l]) then update(l+1,r,f[l,r]+f[l,r]) else update(l+1,r,f[l,r]+b[l]);
    if (f[l,r]>=b[r]) then update(l,r-1,f[l,r]+f[l,r]) else update(l,r-1,f[l,r]+b[r]);
  end;
  ans:=0;
  for i:=0 to m+1 do for j:=0 to m+1 do if (i>j) then ans:=max(ans,f[i,j]);
  writeln(ans);
end.