var
  a,b,c:array[1..100000] of longint; pos,nom,n,i:longint;


procedure find(ll,rr:longint;var pos:longint);
var l,r,m:longint;
begin
  l:=ll; r:=rr;
  while r-l>1 do
  begin
    m:=(l+r) div 2;
    if a[b[m]]<a[ll] then l:=m else r:=m;
  end;
  if a[b[r]]<a[ll] then pos:=b[r] else pos:=b[l];
end;


begin
  readln(n); for i:=1 to n do read(a[i]);
  a[n+1]:=maxlongint; pos:=n+1;
  for i:=n downto 1 do
  begin
    if a[i]<=a[pos] then pos:=i;
    b[i]:=pos;
    find(i,n,nom);
    c[i]:=nom-i-1;
  end;
  for i:=1 to n do write(c[i],' ');
end.