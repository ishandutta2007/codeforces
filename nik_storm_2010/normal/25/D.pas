const max=1000;
var
  g,f:array[1..max,1..max] of boolean; c:array[1..max] of longint;
  used:array[1..max] of boolean; cnt,n,a,b,i,j,x,y:longint;


procedure dfs(nom:longint);
var i:longint;
begin
  used[nom]:=true;
  for i:=1 to n do
    if (g[nom,i]) and (not used[i]) then
    begin
      f[nom,i]:=true; f[i,nom]:=true;
      dfs(i);
    end;
end;


begin
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(a,b);
    g[a,b]:=true; g[b,a]:=true;
  end;
  cnt:=0;
  for i:=1 to n do if (not used[i]) then
  begin
    inc(cnt); c[cnt]:=i;
    dfs(i);
  end;
  writeln(cnt-1); x:=1; y:=2;
  for i:=1 to n do for j:=i+1 to n do
    if (g[i,j]) and (not f[i,j]) then
    begin
      writeln(i,' ',j,' ',c[x],' ',c[y]);
      inc(y);
      if (y>cnt) then begin inc(x); y:=x+1; end;
    end;
end.