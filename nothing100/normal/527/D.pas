var
  n,ans:longint;
  x,w,wh,dx,tr:array [1..200000] of longint;
  tmp:array [1..200000,1..2] of longint;
procedure qsort(x,y:longint);
var
  l,r,mid,q:longint;
begin
  l:=x; r:=y; mid:=tmp[random(y-x+1)+x,1];
  repeat
    while (tmp[l,1]<mid) do inc(l);
    while (tmp[r,1]>mid) do dec(r);
    if l<=r then
    begin
      q:=tmp[l,1]; tmp[l,1]:=tmp[r,1]; tmp[r,1]:=q;
      q:=tmp[l,2]; tmp[l,2]:=tmp[r,2]; tmp[r,2]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
function get(x:longint):longint;
var
  l,r,o,mid:longint;
begin
  l:=1; r:=n; o:=0;
  while l<=r do
  begin
    mid:=(l+r) shr 1;
    if dx[mid]<=x then
    begin
      l:=mid+1;
      o:=mid;
    end
    else r:=mid-1;
  end;
  exit(o);
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
function low(x:longint):longint;
begin
  exit(x and (-x));
end;
function gets(x:longint):longint;
var
  o:longint;
begin
  o:=0;
  while x>0 do
  begin
    o:=max(o,tr[x]);
    x:=x-low(x);
  end;
  exit(o);
end;
procedure ins(x,y:longint);
begin
  while x<=n do
  begin
    tr[x]:=max(tr[x],y);
    x:=x+low(x);
  end;
end;
procedure init;
var
  i,o,p,q:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(x[i],w[i]);
    tmp[i,1]:=x[i]+w[i];
    tmp[i,2]:=i;
  end;
  qsort(1,n);
  for i:=1 to n do
  begin
    dx[i]:=tmp[i,1];
    wh[tmp[i,2]]:=i;
  end;
  for i:=1 to n do
  begin
    tmp[i,1]:=x[i];
    tmp[i,2]:=i;
  end;
  qsort(1,n);
  for i:=1 to n do
  begin
    o:=x[tmp[i,2]]-w[tmp[i,2]];
    p:=get(o);
    q:=gets(p)+1;
    ans:=max(q,ans);
    ins(wh[tmp[i,2]],q);
  end;
  writeln(ans);
end;
begin
  init;
end.