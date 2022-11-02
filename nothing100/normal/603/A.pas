var
  s:ansistring;
  n:longint;
  dp:array [0..100000,0..2,0..1] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i,j,k:longint;
begin
  readln(n);
  readln(s);
  for i:=1 to n do
  begin
    if s[i]='1' then
    begin
      dp[i,0,1]:=dp[i-1,0,0]+1;
      dp[i,1,1]:=max(dp[i-1,1,0],dp[i-1,0,1])+1;
      dp[i,2,1]:=max(dp[i-1,2,0],dp[i-1,1,1])+1;
    end
    else if s[i]='0' then
    begin
      dp[i,0,0]:=dp[i-1,0,1]+1;
      dp[i,1,0]:=max(dp[i-1,1,1],dp[i-1,0,0])+1;
      dp[i,2,0]:=max(dp[i-1,2,1],dp[i-1,1,0])+1;
    end;
    for j:=0 to 2 do
    for k:=0 to 1 do dp[i,j,k]:=max(dp[i,j,k],dp[i-1,j,k]);
  end;
  writeln(max(dp[n,2,0],dp[n,2,1]));
end;
begin
  init;
end.