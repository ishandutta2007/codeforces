uses
  math;
const
  md=1000000007;
var
  a:array[0..100000] of int64;
  n,x,y,cnt,sum:int64;
  i,j:longint;

function power(x,y:int64):int64;
var
  c:int64;
begin
  if (y=0) then exit(1);
  c:=power(x,y div 2);
  c:=(c*c) mod md;
  if (odd(y)) then power:=(c*x) mod md else power:=c;
end;

begin
  readln(n,x);
  for i:=1 to n do
  begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  for i:=1 to n do a[i]:=sum-a[i];
  i:=n;
  cnt:=0;
  y:=a[n];
  a[0]:=maxlongint;
  while (i>0) do
  begin
    j:=i;
    while (j>0) and (a[j]=a[i]) do dec(j);
    cnt:=cnt+i-j;
    while (y<>a[j]) and (cnt mod x=0) do
    begin
      inc(y);
      cnt:=cnt div x;
    end;
    i:=j;
    if (y=a[j]) then continue;
    if (cnt mod x<>0) then break;
  end;
  writeln(power(x,min(sum,y)));
end.