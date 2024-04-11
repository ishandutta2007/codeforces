const n=100;
var
  g:array[1..n,1..n] of longint; cnt,kk,i,j,k,m:longint;


begin
  readln(kk);
  for i:=1 to n do for j:=i-1 downto 1 do
  begin
    m:=0;
    for k:=1 to n do if (g[i,k]=1) and (g[j,k]=1) then inc(m);
    if (cnt+m<=kk) then
    begin
      cnt:=cnt+m;
      g[i,j]:=1; g[j,i]:=1;
    end;
  end;
  writeln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do write(g[i,j]);
    writeln;
  end;
end.