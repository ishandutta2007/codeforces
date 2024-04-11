var
  f:array[0..1000] of boolean; p,a,c,l:array[1..1000] of longint;
  kol,n,x,i,j:longint;


procedure dfs(nom:longint);
begin
  if c[nom]<>0 then exit;
  dfs(p[nom]);
  c[nom]:=c[p[nom]]; inc(l[c[nom]]);
  a[nom]:=a[p[nom]]+1;
end;


begin

  readln(n,x); kol:=0;
  for i:=1 to n do
  begin
    read(p[i]);
    if p[i]=0 then
    begin
      inc(kol); c[i]:=kol;
      a[i]:=1; l[kol]:=1;
    end;
  end;
  for i:=1 to n do if c[i]=0 then dfs(i);
  f[0]:=true;
  for i:=1 to kol do
  begin
    if c[x]=i then continue;
    for j:=1000 downto 0 do if f[j] then f[j+l[i]]:=true;
  end;
  for i:=0 to n do if f[i] then writeln(i+a[x]);

end.