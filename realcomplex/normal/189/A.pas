var
  n,a,b,c, i:longint;
  dp:array[0..4000] of longint;
  exists:array[0..4000] of longint;
begin
  readln(n,a,b,c);
  for i := 0 to n do
    dp[i] := 0;
  for i := 0 to n do
    exists[i] := 0;
  exists[0] := 1;
  for i := 1 to n do
  begin
    if i >= a then 
    begin
      if (dp[i - a] + 1 > dp[i]) and (exists[i - a] = 1) then
        dp[i] := dp[i - a] + 1;
    end;
    if i >= b then 
    begin
      if (dp[i - b] + 1 > dp[i]) and (exists[i - b] = 1) then
        dp[i] := dp[i - b] + 1;
    end;
    if i >= c then 
    begin
      if (dp[i - c] + 1 > dp[i]) and (exists[i - c] = 1) then
        dp[i] := dp[i - c] + 1;
    end;
    if dp[i] >= 1 then
      exists[i] := 1;
  end;
  writeln(dp[n]);
end.