uses
  math;
var
  a:array[1..100000] of int64;
  sum,r,l,q,x,n,m:int64;
  i:longint;

function maybe(u:int64):boolean;
var
  xx:int64;
  i:longint;
begin
  if (u<q) then exit(false);
  if (u*(n-1)<sum) then exit(false);
  xx:=0;
  for i:=1 to n do xx:=xx+(u-a[i]);
  if (xx<u) then exit(false);
  maybe:=true;
end;

begin
  readln(n);
  sum:=0;
  q:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    sum:=sum+a[i];
    q:=max(q,a[i]);
  end;
  l:=0; r:=10000000000000;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (maybe(m)) then r:=m else l:=m;
  end;
  if (maybe(l)) then writeln(l) else writeln(r);
end.