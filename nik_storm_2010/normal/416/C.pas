uses
  math;
const
  l=2000+10;
var
  f,p:array[0..l,0..l] of longint;
  a:array[1..3,1..l] of longint;
  b,ans:array[1..2,1..l] of longint;
  n,m,i,j,cnt:longint;

procedure sorta(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[1,random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[1,i]<d) do inc(i);
    while (a[1,j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
      w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
      w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
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
  d:=b[1,random(r-l+1)+l];
  while (i<=j) do
  begin
    while (b[1,i]<d) do inc(i);
    while (b[1,j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=b[1,i]; b[1,i]:=b[1,j]; b[1,j]:=w;
      w:=b[2,i]; b[2,i]:=b[2,j]; b[2,j]:=w;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then sortb(i,r);
  if (l<j) then sortb(l,j);
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(a[1,i],a[2,i]);
    a[3,i]:=i;
  end;
  readln(m);
  for i:=1 to m do
  begin
    read(b[1,i]);
    b[2,i]:=i;
  end;
  randomize;
  sorta(1,n);
  sortb(1,m);
  for i:=1 to n+1 do for j:=1 to m+1 do f[i,j]:=-maxlongint;
  f[1,1]:=0;
  for i:=1 to n+1 do for j:=1 to m+1 do
  begin
    if (f[i,j]=-maxlongint) then continue;
    if (i<>n+1) and (j<>m+1) and (a[1,i]<=b[1,j]) and (f[i+1,j+1]<f[i,j]+a[2,i]) then
    begin
      f[i+1,j+1]:=f[i,j]+a[2,i];
      p[i+1,j+1]:=3;
    end;
    if (i<>n+1) and (f[i+1,j]<f[i,j]) then
    begin
      f[i+1,j]:=f[i,j];
      p[i+1,j]:=1;
    end;
    if (j<>m+1) and (f[i,j+1]<f[i,j]) then
    begin
      f[i,j+1]:=f[i,j];
      p[i,j+1]:=2;
    end;
  end;
  cnt:=0;
  i:=n+1;
  j:=m+1;
  while (true) do
  begin
    if (i+j=2) then break;
    if (p[i,j]=3) then
    begin
      inc(cnt);
      ans[1,cnt]:=a[3,i-1];
      ans[2,cnt]:=b[2,j-1];
      dec(i);
      dec(j);
      continue;
    end;
    if (p[i,j]=2) then
    begin
      dec(j);
      continue;
    end;
    if (p[i,j]=1) then
    begin
      dec(i);
      continue;
    end;
  end;
  writeln(cnt,' ',f[n+1,m+1]);
  for i:=1 to cnt do writeln(ans[1,i],' ',ans[2,i]);
end.