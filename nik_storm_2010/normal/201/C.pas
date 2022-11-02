uses
  math;
const
  ll=100000;
var
  a,r,l,sum:array[1..ll] of int64;
  ans,cur:int64;
  i,j,n:longint;

begin
  readln(n);
  for i:=1 to n-1 do read(a[i]);
  for i:=2 to n do
  begin
    if (a[i-1]=1) then continue;
    l[i]:=l[i-1]+a[i-1];
    if (odd(a[i-1])) then dec(l[i]);
  end;
  for i:=n-1 downto 1 do
  begin
    if (a[i]=1) then continue;
    r[i]:=r[i+1]+a[i];
    if (odd(a[i])) then dec(r[i]);
  end;
  for i:=2 to n do
  begin
    sum[i]:=sum[i-1]+a[i-1];
    if not(odd(a[i-1])) then dec(sum[i]);
  end;
  for i:=1 to n do
  begin
    cur:=max(cur,l[i]-sum[i]);
    ans:=max(ans,cur+r[i]+sum[i]);
  end;
  writeln(ans);
end.