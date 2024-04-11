const
  lim=1000000+10;
var
  left,right:array[1..lim] of int64;
  n,d,m,l,x,ost:int64;
  i:longint;

begin
  readln(n,d,m,l);
  for i:=1 to n do
  begin
    left[i]:=(i-1)*m;
    right[i]:=(i-1)*m+l;
  end;
  x:=0;
  i:=1;
  while (i<=n) do
  begin
    ost:=right[i]-x;
    x:=x+d*(ost div d);
    x:=x+d;
    inc(i);
    while (i<=n) and (right[i]<x) do inc(i);
    if (i>n) or (not((left[i]<=x) and (x<=right[i])))  then break;
  end;
  writeln(x);
end.