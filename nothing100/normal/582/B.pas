var
  ans:int64;
  n,t:longint;
  a:array [1..10000] of longint;
  num,sum:array [1..300] of int64;
function max(x,y:int64):int64;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i,l,j:longint;
  o:int64;
begin
  read(n,t);
  for i:=1 to n do read(a[i]);
  if n<=t then l:=n
  else l:=t;
  for i:=2 to l do
  for j:=1 to n do a[i*n-n+j]:=a[j];
  num[a[1]]:=1;
  for i:=2 to n*l do
  begin
    o:=0;
    for j:=1 to a[i] do o:=max(o,num[j]);
    num[a[i]]:=o+1;
  end;
  for i:=1 to n do inc(sum[a[i]]);
  for i:=1 to 300 do ans:=max(ans,num[i]);
  o:=0;
  for i:=1 to 300 do o:=max(o,sum[i]);
  ans:=ans+o*(t-l);
  writeln(ans);
end;
begin
  init;
end.