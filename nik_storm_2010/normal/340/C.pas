var
  a,l,r:array[0..200000] of int64; n,x,y,d:int64; i:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
begin
  i:=l; j:=r; d:=a[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (a[i]<d) do inc(i);
    while (a[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if (i<r) then quicksort(i,r);
  if (l<j) then quicksort(l,j);
end;


function gcd(x,y:int64):int64;
begin
  while (x>0) and (y>0) do
    if (x>y) then x:=x mod y else y:=y mod x;
  gcd:=x+y;
end;


begin
  readln(n); for i:=1 to n do read(a[i]);
  randomize; quicksort(1,n);
  for i:=1 to n do l[i]:=l[i-1]+a[i];
  for i:=n downto 1 do r[i]:=r[i+1]+a[i];
  x:=0; y:=n;
  for i:=1 to n do
    x:=x+a[i]*(i-1)-l[i-1]+r[i+1]-a[i]*(n-i)+a[i];
  d:=gcd(x,y);
  writeln(x div d,' ',y div d);
end.