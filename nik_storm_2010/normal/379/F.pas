const
  lim=2000000;
  log=20;
type
  edges=record
    t,n:longint;
  end;
var
  dp,start,tin,tout,quest:array[0..lim] of longint;
  f:array[0..lim,0..log] of longint;
  ee:array[0..lim] of edges;
  time,cnt,ans,max,n,v,q,i,j,cur:longint;

procedure add(x,y:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

procedure dfs(nom,depth,prev:longint);
var
  e:longint;
begin
  inc(time);
  tin[nom]:=time;
  dp[nom]:=depth;
  f[nom,0]:=prev;
  e:=start[nom];
  while (e<>0) do
  begin
    dfs(ee[e].t,depth+1,nom);
    e:=ee[e].n;
  end;
  inc(time);
  tout[nom]:=time;
end;

function ancestor(x,y:longint):boolean;
begin
  if (tin[x]<=tin[y]) and (tout[y]<=tout[x]) then exit(true) else exit(false);
end;

function lca(a,b:longint):longint;
var
  i:longint;
begin
  if (ancestor(a,b)) then exit(a);
  if (ancestor(b,a)) then exit(b);
  for i:=log downto 0 do if (not ancestor(f[a,i],b)) then a:=f[a,i];
  exit(f[a,0]);
end;

begin
  readln(q);
  add(1,2);
  add(1,3);
  add(1,4);
  n:=4;
  for i:=1 to q do
  begin
    readln(quest[i]);
    add(quest[i],n+1);
    add(quest[i],n+2);
    n:=n+2;
  end;
  dfs(1,0,1);
  for i:=1 to n do for j:=1 to log do f[i,j]:=f[f[i,j-1],j-1];
  ans:=2; max:=1; v:=2; n:=4;
  for i:=1 to q do
  begin
    if (dp[quest[i]]+1>max) then
    begin
      inc(ans);
      max:=max+1;
      v:=n+1;
    end
    else
    begin
      cur:=dp[quest[i]]+dp[v]-2*dp[lca(quest[i],v)]+1;
      if (cur>ans) then ans:=cur;
    end;
    n:=n+2;
    writeln(ans);
  end;
end.