var
  a:array[1..1000] of array of longint; k:array[1..1000] of longint;
  ans,i1,i2,k1,k2,n,i,j,l,r:longint;


procedure sort(nom,l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[nom,random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[nom,i]<d) do inc(i);
    while (a[nom,j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[nom,i]; a[nom,i]:=a[nom,j]; a[nom,j]:=w;
      inc(i); dec(j);
    end;
  end;
  if (i<r) then sort(nom,i,r);
  if (l<j) then sort(nom,l,j);
end;


begin
  readln(n); randomize;
  for i:=1 to n do
  begin
    read(k[i]); setlength(a[i],k[i]+2);
    for j:=1 to k[i] do read(a[i,j]);
    readln;
    sort(i,1,k[i]);
  end;
  for i:=1 to n do
  begin
    l:=i-1; i1:=1; if (l=0) then l:=n;
    r:=i+1; i2:=1; if (r>n) then r:=1;
    for j:=1 to k[i] do
    begin
      k1:=0; k2:=0;
      while (i1<=k[l]) and (a[l,i1]<=a[i,j]) do begin inc(i1); inc(k1); end;
      while (i2<=k[r]) and (a[r,i2]<=a[i,j]) do begin inc(i2); inc(k2); end;
      if (j<>1) and (k1<>k2) then inc(ans);
    end;
  end;
  writeln(ans);
end.