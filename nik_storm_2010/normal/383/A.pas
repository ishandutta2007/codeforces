uses
  math;
var
  a,b,c:array[1..300000] of longint;
  ans1,ans2,cnt:int64;
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  cnt:=0; ans1:=0;
  for i:=1 to n do if (a[i]=1) then inc(cnt) else ans1:=ans1+cnt;
  cnt:=0; ans2:=0;
  for i:=n downto 1 do if (a[i]=0) then inc(cnt) else ans2:=ans2+cnt;
  writeln(min(ans1,ans2));
end.