const
  ll=500;
var
  g:array[1..ll,1..ll] of longint;
  a:array[1..ll] of longint;
  used:array[1..ll] of boolean;
  n,m,k,i,j,ans:longint;

procedure dfs(nom,prev:longint);
var
  i:longint;
begin
  used[nom]:=true;
  for i:=1 to n do
  begin
    if (g[nom,i]=0) or (i=prev) then continue;
    if (not used[i]) then dfs(i,nom) else
    begin
      if (ans=m) then continue;
      g[nom,i]:=0;
      g[i,nom]:=0;
      dec(ans);
    end;
  end;
end;

begin
  readln(n,m,k);
  for i:=1 to k do read(a[i]);
  ans:=(n*(n-1)) div 2-k+1;
  if (k=n) or (m>ans) then begin writeln(-1); halt; end;
  for i:=1 to n do  for j:=1 to n do
  begin
    if (i=j) then continue;
    g[i,j]:=1;
  end;
  for i:=2 to k do
  begin
    g[a[1],a[i]]:=0;
    g[a[i],a[1]]:=0;
  end;
  dfs(1,-1);
  for i:=1 to n do for j:=i+1 to n do if (g[i,j]=1) then writeln(i,' ',j);
end.