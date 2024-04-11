uses math; const l=2000;
var
  cnt,used:array[1..l] of longint; g:array[1..l,1..l] of longint;
  bad:array[1..l] of boolean; ans,kol,n,k,m,j,a,b,i:longint;


procedure dfs(nom,col:longint);
var i:longint;
begin
  used[nom]:=col; inc(cnt[col]);
  for i:=1 to n do if (g[nom,i]=1) and (used[i]=0) then dfs(i,col);
end;


begin
  readln(n); readln(k);
  for i:=1 to k do
  begin
    readln(a,b);
    g[a,b]:=1; g[b,a]:=1;
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(a,b);
    g[a,b]:=-1; g[b,a]:=-1;
  end;
  for i:=1 to n do if (used[i]=0) then
  begin
    inc(kol);
    dfs(i,kol);
  end;
  for i:=1 to n do for j:=1 to n do
    if (used[i]=used[j]) and (g[i,j]=-1) then bad[used[i]]:=true;
  for i:=1 to kol do if (not bad[i]) then ans:=max(ans,cnt[i]);
  writeln(ans);

end.