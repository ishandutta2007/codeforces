const
  md=round(1e9)+7;
  ln=20000;
  lm=500;
var
  c:array[0..ln,0..lm] of longint;
  a:array[0..ln] of longint;
  x,n,i,j,k,cnt:longint;
  ans:int64;

procedure factor(x:longint);
var
  i:longint;
begin
  i:=2;
  while (i*i<=x) do
  begin
    while (x mod i=0) do begin inc(cnt); a[cnt]:=i; x:=x div i; end;
    inc(i);
  end;
  if (x<>1) then begin inc(cnt); a[cnt]:=x; end;
end;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=a[random(r-l+1)+l];
  repeat
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i); dec(j);
    end;
  until (i>j);
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

begin
  for i:=0 to ln do c[i,0]:=1;
  for i:=1 to ln do for j:=1 to lm do
  begin
    c[i,j]:=c[i-1,j]+c[i-1,j-1];
    if (c[i,j]>=md) then c[i,j]:=c[i,j]-md;
  end;
  readln(n);
  for i:=1 to n do begin read(x); factor(x); end;
  randomize;
  sort(1,cnt);
  ans:=1; i:=1;
  while (i<=cnt) do
  begin
    j:=i;
    while (i<=cnt) and (a[i]=a[j]) do inc(i);
    k:=i-j;
    ans:=(ans*c[n+k-1,n-1]) mod md;
  end;
  writeln(ans);
end.