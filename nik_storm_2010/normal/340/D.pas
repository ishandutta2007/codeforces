var
  a,f:array[0..200000] of longint; nom,n,i:longint;


procedure find(x:longint;var nom:longint);
var l,r,m:longint;
begin
  l:=0; r:=n;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (x<=f[m]) then r:=m else l:=m;
  end;
  if (f[l]<=x) then nom:=l else nom:=r;
end;


begin
  readln(n); for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=maxlongint;
  for i:=1 to n do
  begin
    find(a[i],nom);
    if (f[nom]<=a[i]) and (a[i]<=f[nom+1]) then f[nom+1]:=a[i];
  end;
  for i:=n downto 1 do if (f[i]<>maxlongint) then begin writeln(i); halt; end;
end.