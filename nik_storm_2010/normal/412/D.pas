const
  l=200000;
var
  x,y,res:array[0..l] of longint;
  used:array[0..l] of boolean;
  n,m,i,w,j,st,plus,k:longint;

procedure sort(l,r:longint);
var
  i,j,xx,yy,w:longint;
begin
  i:=l; j:=r;
  w:=random(r-l+1)+l;
  xx:=x[w];
  yy:=y[w];
  repeat
    while (x[i]<xx) or ((x[i]=xx) and (y[i]<yy)) do inc(i);
    while (x[j]>xx) or ((x[j]=xx) and (y[j]>yy)) do dec(j);
    if (i<=j) then
    begin
      w:=x[i]; x[i]:=x[j]; x[j]:=w;
      w:=y[i]; y[i]:=y[j]; y[j]:=w;
      inc(i); dec(j);
    end;
  until (i>j);
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

function have(xx,yy:longint):boolean;
var
  l,r,mid,ql,qr:longint;
begin
  l:=0; r:=m;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (x[mid]<xx) then l:=mid else r:=mid;
  end;
  if (x[r]<>xx) then exit(false);
  ql:=r;
  l:=ql; r:=m+1;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (x[mid]<=xx) then l:=mid else r:=mid;
  end;
  qr:=l;
  l:=ql; r:=qr+1;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (y[mid]<=yy) then l:=mid else r:=mid;
  end;
  exit(y[l]=yy);
end;

begin
  readln(n,m);
  for i:=1 to m do readln(x[i],y[i]);
  randomize;
  sort(1,m);
  plus:=2+random(n div 10);
  res[1]:=n;
  st:=1;
  k:=1;
  for i:=2 to n do
  begin
    res[i]:=st;
    st:=st+plus;
    if (st>=n) then begin inc(k); st:=k; end;
  end;
  for i:=n-1 downto 1 do
  begin
    j:=i;
    while (j<=n) and (have(res[j],res[j+1])) do
    begin
      w:=res[j]; res[j]:=res[j+1]; res[j+1]:=w;
      inc(j);
    end;
  end;
  for i:=1 to n do write(res[i],' ');
end.