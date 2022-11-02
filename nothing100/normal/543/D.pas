const mo=1000000007;
type
  bian=record
         point,next:longint;
         suf,pre,f:int64;
       end;
var
  n,tot:longint;
  dp,sum,hsum:array [1..200000] of int64;
  fa,g,queue,num:array [1..200000] of longint;
  b:array [1..400000] of bian;
procedure build(x,y:longint);
begin
  inc(tot); b[tot].point:=y; b[tot].next:=g[x]; g[x]:=tot;
end;
function ksm(x,y:int64):int64;
var
  o:int64;
begin
  o:=1;
  while y<>0 do
  begin
    if y and 1=1 then o:=(o*x) mod mo;
    x:=(x*x) mod mo;
    y:=y shr 1;
  end;
  exit(o);
end;
procedure dfs(x:longint);
var
  t:longint;
begin
  t:=g[x];
  sum[x]:=1;
  while t<>0 do
  begin
    if b[t].point<>fa[x] then
    begin
      fa[b[t].point]:=x;
      dfs(b[t].point);
      sum[x]:=(sum[x]*(sum[b[t].point]+1)) mod mo;
    end;
    t:=b[t].next;
  end;
  t:=g[x];
  while t<>0 do
  begin
    if b[t].point<>fa[x] then
    begin
      inc(num[x]); queue[num[x]]:=t;
    end;
    t:=b[t].next;
  end;
  for t:=1 to num[x] do
  begin
    b[queue[t]].pre:=sum[b[queue[t]].point]+1;
    if t<>1 then b[queue[t]].pre:=(b[queue[t]].pre*b[queue[t-1]].pre) mod mo;
  end;
  for t:=num[x] downto 1 do
  begin
    b[queue[t]].suf:=sum[b[queue[t]].point]+1;
    if t<>num[x] then b[queue[t]].suf:=(b[queue[t]].suf*b[queue[t+1]].suf) mod mo;
  end;
  for t:=1 to num[x] do
  begin
    b[queue[t]].f:=1;
    if t<>1 then b[queue[t]].f:=(b[queue[t]].f*b[queue[t-1]].pre) mod mo;
    if t<>num[x] then b[queue[t]].f:=(b[queue[t]].f*b[queue[t+1]].suf) mod mo;
  end;
end;
procedure dfss(x,y:int64);
var
  t,o:longint;
begin
  t:=g[x];
  dp[x]:=(sum[x]*(y+1)) mod mo;
  while t<>0 do
  begin
    if b[t].point<>fa[x] then
    begin
      o:=(b[t].f*(y+1)) mod mo;
      dfss(b[t].point,o);
    end;
    t:=b[t].next;
  end;
end;
procedure init;
var
  i,j,o:longint;
begin
  read(n);
  for i:=2 to n do
  begin
    read(o);
    build(o,i);
    build(i,o);
  end;
  dfs(1);
  dfss(1,0);
  for i:=1 to n do write(dp[i],' ');
end;
begin
  init;
end.