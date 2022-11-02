var
  a,b,c,f,ll:array[0..300000] of int64; n,i,kol,l,r,nom:longint; ans:int64;


procedure quicksort(l,r:longint);
var i,j,d1,d2,w:longint;
begin
  i:=l; j:=r; w:=random(r-l+1)+l;
  d1:=b[w]; d2:=c[w];
  while i<=j do
  begin
    while (b[i]<d1) or ((b[i]=d1)and(c[i]<d2)) do inc(i);
    while (b[j]>d1) or ((b[j]=d1)and(c[j]>d2)) do dec(j);
    if i<=j then
    begin
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
      w:=c[i]; c[i]:=c[j]; c[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


function sum(l,r:longint):int64;
begin
  if l>r then exit(0) else exit(f[r-1]-f[l]);
end;


procedure find(x:int64;var nom:longint);
var l,r,m:longint;
begin
  l:=1; r:=n;
  while r-l>1 do
  begin
    m:=(r+l) div 2;
    if (x<b[m]) then r:=m else l:=m;
  end;
  if (b[r]=x) then nom:=c[r] else nom:=c[l];
end;


begin

  readln(n);
  for i:=1 to n do
  begin
    read(a[i]); c[i]:=i;
    if a[i]>0 then f[i]:=f[i-1]+a[i] else f[i]:=f[i-1];
  end;
  b:=a; randomize; quicksort(1,n);
  ans:=-maxlongint;
  for i:=1 to n do
  begin
    find(a[i],nom);
    if (nom<>i) and (a[i]+a[nom]+sum(i,nom)>ans) then
    begin
      ans:=a[i]+a[nom]+sum(i,nom);
      l:=i; r:=nom;
    end;
  end;
  kol:=0;
  for i:=1 to n do
  begin
    if not((l<=i) and (i<=r)) then begin inc(kol); ll[kol]:=i; end else
    if (i<>l) and (i<>r) and (a[i]<0) then begin inc(kol); ll[kol]:=i; end;
  end;
  writeln(ans,' ',kol);
  for i:=1 to kol do write(ll[i],' ');

end.