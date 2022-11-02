uses
  math;
const
  l=200;
var
  cnt,a:array[0..l] of longint;
  ans,n,k,i,x:longint;

begin
  readln(n,k);
  for i:=1 to n do
  begin
    read(a[i]);
    if (a[i]=1) then inc(cnt[i mod k]);
  end;
  x:=n div k;
  for i:=0 to k-1 do ans:=ans+min(cnt[i],x-cnt[i]);
  writeln(ans);
end.