type
  tree=record
         ch:array [0..25] of longint;
         sum:longint;
       end;
  bian=record
         point,next:longint;
       end;
var
  n,tot,max,num:longint;
  v,root,dep,tmp,d,g:array [0..300000] of longint;
  ch:array [0..300000] of char;
  b:array [0..600000] of bian;
  tr:array [0..300000] of tree;
procedure build(x,y:longint);
begin
  inc(tot); b[tot].point:=y; b[tot].next:=g[x]; g[x]:=tot;
  inc(tot); b[tot].point:=x; b[tot].next:=g[y]; g[y]:=tot;
end;
procedure dfs(x,y:longint);
var
  t:longint;
begin
  t:=g[x];
  dep[x]:=dep[y]+1;
  while t<>0 do
  begin
    if b[t].point<>y then dfs(b[t].point,x);
    t:=b[t].next;
  end;
end;
procedure qsort(x,y:longint);
var
  l,r,q,mid:longint;
begin
  l:=x; r:=y; mid:=dep[tmp[(l+r) shr 1]];
  repeat
    while dep[tmp[l]]<mid do inc(l);
    while dep[tmp[r]]>mid do dec(r);
    if l<=r then
    begin
      q:=tmp[l]; tmp[l]:=tmp[r]; tmp[r]:=q;
      inc(l); dec(r);
    end;
  until l>r;
  if x<r then qsort(x,r);
  if l<y then qsort(l,y);
end;
procedure maintain(x:longint);
var
  t:longint;
begin
  tr[x].sum:=0;
  for t:=0 to 25 do tr[x].sum:=tr[x].sum+tr[tr[x].ch[t]].sum;
  inc(tr[x].sum);
end;
procedure dfss(x,y:longint);
var
  t,o:longint;
begin
  o:=ord(ch[y])-ord('a');
  if tr[x].ch[o]=0 then tr[x].ch[ord(ch[y])-ord('a')]:=y
  else for t:=0 to 25 do if tr[y].ch[t]<>0 then dfss(tr[x].ch[o],tr[y].ch[t]);
  maintain(x);
end;
procedure hb(x:longint);
var
  t:longint;
begin
  t:=g[tmp[x]];
  while t<>0 do
  begin
    if dep[b[t].point]>dep[tmp[x]] then dfss(tmp[x],b[t].point);
    t:=b[t].next;
  end;
  maintain(tmp[x]);
  d[tmp[x]]:=tr[tmp[x]].sum;
end;
procedure init;
var
  i,o,p:longint;
begin
  read(n);
  for i:=1 to n do read(v[i]);
  readln;
  for i:=1 to n do read(ch[i]);
  for i:=1 to n-1 do
  begin
    read(o,p);
    build(o,p);
  end;
  dfs(1,0);
  for i:=1 to n do tmp[i]:=i;
  qsort(1,n);
  for i:=n downto 1 do hb(i);
  for i:=1 to n do
  if v[i]+d[i]>max then
  begin
    max:=v[i]+d[i];
    num:=1;
  end
  else if v[i]+d[i]=max then inc(num);
  writeln(max);
  writeln(num);
end;
begin
  init;
end.