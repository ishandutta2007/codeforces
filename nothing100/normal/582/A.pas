var
  n,zs:longint;
  a,num,sum,c:array [1..250000] of longint;
function gcd(x,y:longint):longint;
begin
  if x mod y=0 then exit(y)
  else exit(gcd(y,x mod y));
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
  if l<y then qsort(l,y);
  if x<r then qsort(x,r);
end;
procedure del(x:longint);
var
  l,r,mid:longint;
begin
  l:=1; r:=zs;
  while l<=r do
  begin
    mid:=(l+r) shr 1;
    if num[mid]=x then
    begin
      sum[mid]:=sum[mid]-2;
      exit;
    end
    else if num[mid]>x then r:=mid-1
    else l:=mid+1;
  end;
end;
procedure init;
var
  i,j,l:longint;
begin
  read(n);
  for i:=1 to n*n do read(a[i]);
  qsort(1,n*n);
  for i:=1 to n*n do
  begin
    if (i=1) or (a[i]<>a[i-1]) then inc(zs);
    num[zs]:=a[i];
    inc(sum[zs]);
  end;
  for i:=n downto 1 do
  begin
    while sum[zs]=0 do dec(zs);
    c[i]:=num[zs];
    dec(sum[zs]);
    for j:=(i+1) to n do del(gcd(c[i],c[j]));
  end;
  for i:=1 to n do write(c[i],' ');
end;
begin
  init;
end.