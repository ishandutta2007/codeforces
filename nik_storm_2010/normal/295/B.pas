uses math; const inf=round(2e9);
var
    g:array[1..500,1..500] of int64; quest,q:array[1..500] of int64;
      used:array[1..500] of boolean; test,n,i,j:longint;


begin

  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do read(g[i,j]);
      readln;
    end;
  for i:=1 to n do read(q[i]);
  for test:=n downto 1 do
  begin
    used[q[test]]:=true;
    for i:=1 to n do
      for j:=1 to n do
      if g[i,q[test]]+g[q[test],j]<g[i,j] then g[i,j]:=g[i,q[test]]+g[q[test],j];
    quest[test]:=0;
    for i:=1 to n do
      for j:=1 to n do
      if (used[i]) and (used[j]) then quest[test]:=quest[test]+g[i,j];
  end;
  for i:=1 to n do write(quest[i],' ');

end.