uses
  math;
const
  l=200000;
var
  a,sum:array[1..l] of longint;
  ans,n,i,j,x:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  i:=1; j:=n;
  while (i<=j) do
  begin
    x:=a[i]-i+1;
    if (x>0) then inc(sum[x]);
    if (i<>j) then
    begin
      x:=a[j]-n+j;
      if (x>0) then inc(sum[x]);
    end;
    inc(i); dec(j);
  end;
  ans:=n;
  for i:=1 to l do ans:=min(ans,n-sum[i]);
  writeln(ans);
end.