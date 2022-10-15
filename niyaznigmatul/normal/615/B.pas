

var
  deg, dp, he, ne, ss, ff : array[0 .. 1234567] of longint;
  was : array[0 .. 1234567] of boolean;
  ans : int64;

function dfs(v : longint) : longint;
var
  e, got : longint;
  begin
    if was[v] then begin
      dfs := dp[v];
      exit;
    end;
    was[v] := true;
    e := he[v];
    dp[v] := 0;
    while e >= 0 do begin
      got := dfs(ff[e]);
      if dp[v] < got then dp[v] := got;
      e := ne[e];
    end;
    inc(dp[v]);
    dfs := dp[v];
  end;

var
  n, m, i, t : longint;
  cur : int64;
begin
  read(n, m);
  for i := 1 to n do deg[i] := 0;
  for i := 1 to m do begin
    read(ss[i], ff[i]);
    if ss[i] < ff[i] then begin
      t := ss[i];
      ss[i] := ff[i];
      ff[i] := t;
    end;
    inc(deg[ss[i]]);
    inc(deg[ff[i]]);
  end;
  for i := 1 to n do he[i] := -1;
  for i := 1 to m do begin
    ne[i] := he[ss[i]];
    he[ss[i]] := i;
  end;
  for i := 1 to n do begin
    if not was[i] then
      dfs(i);
  end;
  ans := -1;
  for i := 1 to n do begin
    cur := int64(deg[i]) * dp[i];
    if cur > ans then begin
      ans := cur;
    end;
  end;
  writeln(ans);
end.