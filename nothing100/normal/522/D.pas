const inf=100000000;
var
  n,m,num:longint;
  tmp:array [0..600000,1..3] of longint;
  a,next,ans:array [1..600000] of longint;
  tr:array [0..600000] of longint;
function min(x,y:longint):longint;
begin
  if x<y then exit(x)
  else exit(y);
end;
procedure qsort(x,y:longint);
var
  l,r,mid,tmpp:longint;
begin
  l:=x; r:=y; mid:=tmp[random(y-x+1)+x,1];
  repeat
    while (l<y) and (tmp[l,1]>mid) do inc(l);
    while (r>x) and (tmp[r,1]<mid) do dec(r);
    if l<=r then
    begin
      tmpp:=tmp[l,1]; tmp[l,1]:=tmp[r,1]; tmp[r,1]:=tmpp;
      tmpp:=tmp[l,2]; tmp[l,2]:=tmp[r,2]; tmp[r,2]:=tmpp;
      tmpp:=tmp[l,3]; tmp[l,3]:=tmp[r,3]; tmp[r,3]:=tmpp;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
function low(x:longint):longint;
begin
  exit(x and (-x));
end;
procedure ins(x,y:longint);
begin
  while x<=n do
  begin
    tr[x]:=min(tr[x],y);
    x:=x+low(x);
  end;
end;
function get(x:longint):longint;
var
  o:longint;
begin
  o:=inf;
  while x>0 do
  begin
    o:=min(o,tr[x]);
    x:=x-low(x);
  end;
  exit(o);
end;
procedure init;
var
  i,j,o:longint;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do tr[i]:=inf;
  for i:=1 to n do
  begin
    tmp[i,1]:=a[i];
    tmp[i,2]:=i;
  end;
  qsort(1,n);
  o:=1;
  for i:=1 to n do
  begin
    if (i<>1) and (tmp[i,1]<>tmp[i-1,1]) then inc(o);
    a[tmp[i,2]]:=o;
  end;
  for i:=1 to m do
  begin
    read(tmp[i,1],tmp[i,2]);
    tmp[i,3]:=i;
  end;
  qsort(1,m);
  tmp[0,1]:=n+1;
  for i:=1 to m do
  begin
    for j:=tmp[i-1,1]-1 downto tmp[i,1] do
    begin
      if next[a[j]]<>0 then ins(next[a[j]],next[a[j]]-j);
      next[a[j]]:=j;
    end;
    ans[tmp[i,3]]:=get(tmp[i,2]);
  end;
  for i:=1 to m do
  if ans[i]=inf then writeln('-1')
  else writeln(ans[i]);
end;
begin
  init;
end.