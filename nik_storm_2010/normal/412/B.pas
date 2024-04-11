uses
  math;
var
  a:array[1..200] of longint;
  n,k,i,ans:longint;

function check(x:longint):boolean;
var
  i,cnt:longint;
begin
  cnt:=0;
  for i:=1 to n do if (a[i]>=a[x]) then inc(cnt);
  if (cnt>=k) then exit(true) else exit(false);
end;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do if (check(i)) then ans:=max(ans,a[i]);
  writeln(ans);
end.