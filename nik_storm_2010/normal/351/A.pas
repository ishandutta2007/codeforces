uses
  math;
var
  a:array[1..4000] of extended;
  all,sum,ans:extended;
  n,i,k:longint;

begin
  readln(n);
  for i:=1 to (2*n) do
  begin
    read(a[i]);
    all:=all+a[i];
    sum:=sum+trunc(a[i]);
    if (frac(a[i])=0) then inc(k);
  end;
  ans:=maxlongint;
  for i:=0 to n do
  begin
    if (k<n-i) then continue;
    ans:=min(ans,abs(all-sum-i));
  end;
  writeln(ans:0:3);
end.