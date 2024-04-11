const
  md=round(1e9)+7;
  lim=300000+10;
type
  edges=record t,n:longint; end;
var
  ee:array[0..2*lim] of edges;
  start,l,r,real,dp:array[0..lim] of longint;
  tree:array[1..2,0..lim] of longint;
  res,quest,kind,cnt,n,i,v,x,k:longint;

procedure add(x,y:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

procedure dfs(nom,prev,depth:longint);
var
  e,t:longint;
begin
  inc(cnt);
  real[nom]:=cnt;
  l[real[nom]]:=cnt;
  dp[real[nom]]:=depth;
  e:=start[nom];
  while (e<>0) do
  begin
    t:=ee[e].t;
    if (t<>prev) then dfs(t,nom,depth+1);
    e:=ee[e].n;
  end;
  r[real[nom]]:=cnt;
end;

procedure modify(nom,i,x:longint);
begin
  while (i<=lim) do
  begin
    tree[nom,i]:=tree[nom,i]+x;
    if (tree[nom,i]<0) then tree[nom,i]:=tree[nom,i]+md;
    if (tree[nom,i]>=md) then tree[nom,i]:=tree[nom,i]-md;
    i:=(i or (i+1));
  end;
end;

function get(nom,i:longint):longint;
var
  res:longint;
begin
  res:=0;
  while (i>=0) do
  begin
    res:=res+tree[nom,i];
    if (res<0) then res:=res+md;
    if (res>=md) then res:=res-md;
    i:=(i and (i+1))-1;
  end;
  get:=res;
end;

begin
  readln(n);
  for i:=2 to n do
  begin
    read(x);
    add(i,x); add(x,i);
  end;
  cnt:=0;
  dfs(1,1,1);
  readln(quest);
  for i:=1 to quest do
  begin
    read(kind);
    if (kind=1) then
    begin
      readln(v,x,k);
      v:=real[v];
      x:=(int64(dp[v])*k+x) mod md;
      modify(1,l[v],+x);
      modify(1,r[v]+1,-x);
      modify(2,l[v],k);
      modify(2,r[v]+1,-k);
    end
    else
    begin
      readln(v);
      v:=real[v];
      res:=(-int64(get(2,v))*dp[v]+get(1,v)) mod md;
      if (res<0) then res:=res+md;
      if (res>=md) then res:=res-md;
      writeln(res);
    end;
  end;
end.