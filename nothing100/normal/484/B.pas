var
  n,ma,ans,tot:longint;
  a:array [1..200000] of longint;
  tr,f:array [1..2000000] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
function low(x:longint):longint;
begin
  exit(x and (-x));
end;
procedure ins(x:longint);
var
  o:longint;
begin
  o:=x;
  while o<=2*ma do
  begin
    tr[o]:=max(tr[o],x);
    o:=o+low(o);
  end;
end;
function get(x:longint):longint;
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
procedure qsort(x,y:longint);
var
  l,r,mid,q:longint;
begin
  l:=x; r:=y; mid:=a[(l+r) shr 1];
  repeat
    while a[l]<mid do inc(l);
    while a[r]>mid do dec(r);
    if l<=r then
    begin
      q:=a[l]; a[l]:=a[r]; a[r]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
procedure init;
var
  i,j,o,p:longint;
begin
  read(n);
  for i:=1 to n do
  begin
    read(o);
    if f[o]=0 then
    begin
      inc(tot);
      a[tot]:=o;
      f[tot]:=1;
    end;
    ma:=max(ma,o);
  end;
  for i:=1 to tot do ins(a[i]);
  for i:=1 to tot do
  if a[i]<>1 then
  begin
    j:=1; o:=0;
    while j*a[i]<ma do
    begin
      o:=max(o,get((j+1)*a[i]-1)-j*a[i]);
      inc(j);
    end;
    ans:=max(ans,o);
  end;
  writeln(ans);
end;
begin
  init;
end.