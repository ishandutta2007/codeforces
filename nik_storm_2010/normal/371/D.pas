const
  l=300000;
var
  tree,a,cur:array[0..l] of int64;
  kind,x,y,n,m:int64;
  i,q:longint;

function sum(x:longint):longint;
var
  res:longint;
begin
  res:=0;
  while (x>=0) do
  begin
    res:=res+tree[x];
    x:=(x and (x+1))-1;
  end;
  exit(res);
end;

procedure mode(x:longint);
begin
  while (x<=l) do
  begin
    inc(tree[x]);
    x:=x or (x+1);
  end;
end;

procedure full(x,y:int64);
var
  mid,l,r:longint;
begin
  l:=x; r:=n+1;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (sum(mid)-sum(l-1)=mid-l+1) then l:=mid else r:=mid;
  end;
  if (cur[l]=a[l]) then l:=r;
  if (cur[l]+y<=a[l]) then cur[l]:=cur[l]+y else
  begin
    if (cur[l]<>a[l]) then mode(l);
    y:=y-a[l]+cur[l];
    cur[l]:=a[l];
    full(l,y);
  end;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  a[n+1]:=maxlongint*maxlongint;
  readln(m);
  for q:=1 to m do
  begin
    read(kind);
    if (kind=1) then
    begin
      readln(x,y);
      full(x,y);
    end
    else
    begin
      readln(x);
      writeln(cur[x]);
    end;
  end;
end.