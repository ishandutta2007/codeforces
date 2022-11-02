var
  a:array[1..1000000] of longint;
  n,l,r,m,i:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

function maybe(m:longint):boolean;
var
  l,r:longint;
begin
  l:=1; r:=m+1;
  while (l<>m+1) do
  begin
    while (r<=n) and (a[l]*2>a[r]) do inc(r);
    if (r=n+1) then exit(false);
    inc(r);
    inc(l);
  end;
  exit(true);
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  randomize;
  sort(1,n);
  l:=0; r:=(n div 2)+1;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (maybe(m)) then l:=m else r:=m;
  end;
  writeln(n-l);
end.