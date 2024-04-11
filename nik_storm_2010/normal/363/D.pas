uses
  math;
var
  a,b:array[1..200000] of longint;
  n,m,cost,l,r,i,x,mid:longint;

procedure sorta(l,r:longint);
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
  if (i<r) then sorta(i,r);
  if (l<j) then sorta(l,j);
end;

procedure sortb(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=b[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (b[i]<d) do inc(i);
    while (b[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sortb(i,r);
  if (l<j) then sortb(l,j);
end;

function maybe(x:longint):longint;
var
  i,j,d,sum:longint;
begin
  d:=cost;
  j:=n;
  sum:=0;
  for i:=x downto 1 do
  begin
    if (a[j]>b[i]) then sum:=sum+b[i] else
    begin
      sum:=sum+a[j];
      if (b[i]-a[j]>d) then exit(-1);
      d:=d-(b[i]-a[j]);
    end;
    dec(j);
  end;
  sum:=max(0,sum-d);
  maybe:=sum;
end;

begin
  readln(n,m,cost);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  randomize;
  sorta(1,n);
  sortb(1,m);
  l:=1; r:=min(n,m);
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    x:=maybe(mid);
    if (x=-1) then r:=mid else l:=mid;
  end;
  x:=maybe(r);
  if (x<>-1) then writeln(r,' ',x) else
  begin
    x:=maybe(l);
    if (x=-1) then writeln(0,' ',0) else writeln(l,' ',x);
  end;
end.