const mo=1000000007;
type
  bian=record
         point,next:longint;
         f:int64;
       end;
var
  n,tot,m:longint;
  fa,dis:array [1..100000,0..17] of longint;
  sum,sq,wsum,wsq,size:array [1..100000] of int64;
  g,deep:array [1..100000] of longint;
  b:array [1..200000] of bian;
procedure build(x,y,z:longint);
begin
  inc(tot); b[tot].point:=y; b[tot].f:=z; b[tot].next:=g[x]; g[x]:=tot;
end;
procedure dfs(x:longint);
var
  t:longint;
begin
  size[x]:=1;
  for t:=1 to trunc(ln(deep[x])/ln(2)) do
  begin
    fa[x,t]:=fa[fa[x,t-1],t-1];
    dis[x,t]:=(dis[x,t-1]+dis[fa[x,t-1],t-1]) mod mo;
  end;
  t:=g[x];
  while t<>0 do
  begin
    if b[t].point<>fa[x,0] then
    begin
      fa[b[t].point,0]:=x;
      dis[b[t].point,0]:=b[t].f;
      deep[b[t].point]:=deep[x]+1;
      dfs(b[t].point);
      sum[x]:=(sum[x]+sum[b[t].point]+size[b[t].point]*b[t].f) mod mo;
      sq[x]:=(sq[x]+sq[b[t].point]+2*sum[b[t].point]*b[t].f+((b[t].f*b[t].f) mod mo)*size[b[t].point]) mod mo;
      size[x]:=size[x]+size[b[t].point];
    end;
    t:=b[t].next;
  end;
end;
procedure dfss(x:longint);
var
  o,p,t,q:longint;
begin
  t:=g[x];
  while t<>0 do
  begin
    if b[t].point<>fa[x,0] then
    begin
      o:=((wsum[x]+sum[x]-sum[b[t].point]-size[b[t].point]*b[t].f) mod mo+mo) mod mo;
      p:=n-size[b[t].point];
      q:=((wsq[x]+sq[x]-sq[b[t].point]-2*sum[b[t].point]*b[t].f-(b[t].f*b[t].f) mod mo*size[b[t].point]) mod mo+mo)mod mo;
      wsum[b[t].point]:=(o+p*b[t].f) mod mo;
      wsq[b[t].point]:=(q+2*o*b[t].f+((b[t].f*b[t].f) mod mo)*p) mod mo;
      dfss(b[t].point);
    end;
    t:=b[t].next;
  end;
end;
function gett(x,y:longint):longint;
var
  i,o,p,get:longint;
  di:int64;
begin
  di:=0;
  o:=x; p:=y;
  if deep[x]<deep[y] then
  begin
    while deep[x]<>deep[y] do
    begin
      i:=trunc(ln(deep[y]-deep[x])/ln(2));
      di:=(di+dis[y,i]) mod mo;
      y:=fa[y,i];
    end;
  end;
  if deep[y]<deep[x] then
  begin
    while deep[x]<>deep[y] do
    begin
      i:=trunc(ln(deep[x]-deep[y])/ln(2));
      di:=(di+dis[x,i]) mod mo;
      x:=fa[x,i];
    end;
  end;
  if (y=x) and (x=o) then
  begin
    get:=(sq[p]+wsq[p]) mod mo;
    get:=((get-2*(wsq[o]+2*wsum[o]*di+((di*di) mod mo)*(n-size[o]))) mod mo+mo) mod mo;
  end
  else
  begin
    i:=trunc(ln(deep[x])/ln(2));
    while i>=0 do
    begin
      if fa[x,i]<>fa[y,i] then
      begin
        di:=(di+dis[x,i]+dis[y,i]) mod mo;
        x:=fa[x,i];
        y:=fa[y,i];
      end;
      dec(i);
    end;
    if x<>y then
    begin
      di:=(di+dis[x,0]+dis[y,0]) mod mo;
      x:=fa[x,0]; y:=fa[y,0];
    end;
    get:=(-sq[p]-wsq[p]) mod mo;
    get:=((get+2*(sq[o]+2*sum[o]*di+((di*di) mod mo)*size[o])) mod mo+mo) mod mo;
  end;
  exit(get);
end;
procedure init;
var
  i,o,p,t:longint;
begin
  read(n);
  for i:=1 to (n-1) do
  begin
    read(o,p,t);
    build(o,p,t);
    build(p,o,t);
  end;
  deep[1]:=1;
  dfs(1);
  dfss(1);
  read(m);
  for i:=1 to m do
  begin
    read(o,p);
    writeln(gett(p,o));
  end;
end;
begin
  init;
end.