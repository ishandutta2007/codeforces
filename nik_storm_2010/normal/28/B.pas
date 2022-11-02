const
  l=200;
var
  g:array[1..l,1..l] of byte;
  p:array[1..l] of longint;
  used:array[1..l] of boolean;
  n,x,i:longint;

procedure dfs(nom:longint);
var
  i:longint;
begin
  used[nom]:=true;
  for i:=1 to n do if (g[nom,i]=1) and (not used[i]) then dfs(i);
end;

begin
  read(n);
  for i:=1 to n do
  begin
    read(x);
    p[x]:=i;
  end;
  for i:=1 to n do
  begin
    read(x);
    if (i+x<=n) then begin g[i,i+x]:=1; g[i+x,i]:=1; end;
    if (i-x>=1) then begin g[i,i-x]:=1; g[i-x,i]:=1; end;
  end;
  for i:=1 to n do
  begin
    fillchar(used,sizeof(used),false);
    dfs(i);
    if (not used[p[i]]) then begin writeln('NO'); halt; end;
  end;
  writeln('YES');
end.