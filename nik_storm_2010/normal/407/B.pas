const
  md=1000000000+7;
  lim=5000;
var
  prev,f:array[0..lim] of longint;
  sum,n,i:longint;

procedure dfs(x,need:longint);
begin
  sum:=sum+f[x];
  if (sum>=md) then sum:=sum-md;
  if (x<>need) then dfs(x+1,need);
end;

begin
  readln(n);
  for i:=1 to n do read(prev[i]);
  f[1]:=2;
  for i:=2 to n do
  begin
    sum:=0;
    dfs(prev[i],i);
    f[i]:=sum+2;
    if (f[i]>=md) then f[i]:=f[i]-md;
  end;
  sum:=0;
  for i:=1 to n do
  begin
    sum:=sum+f[i];
    if (sum>=md) then sum:=sum-md;
  end;
  writeln(sum);
end.