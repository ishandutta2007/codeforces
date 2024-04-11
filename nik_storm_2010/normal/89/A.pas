uses
  math;
var
  a:array[1..100000] of int64;
  n,m,k,res,one:int64;
  i:longint;

begin
  readln(n,m,k);
  for i:=1 to n do read(a[i]);
  if (n mod 2=0) then begin writeln(0); halt; end;
  res:=a[1];
  for i:=1 to n do if (odd(i)) then res:=min(res,a[i]);
  one:=(n+1) div 2;
  m:=m div one;
  writeln(min(m*k,res));
end.