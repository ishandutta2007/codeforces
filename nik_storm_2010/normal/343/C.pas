var
  a,b:array[1..200000] of int64;
  r,l,n,m,mid:int64;
  i:longint;

function check(x:int64):boolean;
var
  prev,j,i:longint;
begin
  j:=1;
  for i:=1 to n do
  begin
    if (j>m) then break;
    if (b[j]<a[i]) then
    begin
      prev:=j;
      if (a[i]-b[j]>x) then exit(false);
      while (b[j]<a[i]) and (j<=m) do inc(j);
      while (j<=m) do
        if ((b[j]-a[i])*2+a[i]-b[prev]<=x) or ((a[i]-b[prev])*2+b[j]-a[i]<=x) then inc(j) else break
    end
      else
    begin
      while (j<=m) do if (b[j]-a[i]<=x) then inc(j) else break;
    end;
  end;
  if (j>m) then exit(true) else exit(false);
end;

begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=1 to m do read(b[i]);
  l:=0; r:=round(1e15);
  while (r-l>1) do
  begin
    mid:=(r+l) div 2;
    if (check(mid)) then r:=mid else l:=mid;
  end;
  if (check(l)) then writeln(l) else writeln(r);
end.