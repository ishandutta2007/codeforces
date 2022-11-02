const
  lim=200000;
type
  edges=record t,n,w:longint; end;
var
  start,size,down,up:array[1..lim] of int64;
  ee:array[1..lim] of edges;
  cnt,n,i,u,v,w:longint;
  ans,cur:int64;

function check(x:longint):longint;
begin
  check:=0;
  while (x<>0) do
  begin
    if (x mod 10<>4) and (x mod 10<>7) then exit;
    x:=x div 10;
  end;
  check:=1;
end;

procedure add(x,y,z:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  ee[cnt].w:=z;
  start[x]:=cnt;
end;

procedure dfsdown(nom,prev:longint);
var
  e,t:longint;
begin
  e:=start[nom];
  size[nom]:=1;
  while (e<>0) do
  begin
    t:=ee[e].t;
    if (t<>prev) then
    begin
      dfsdown(t,nom);
      if (ee[e].w=0)
      then down[nom]:=down[nom]+down[t]
      else down[nom]:=down[nom]+size[t];
      size[nom]:=size[nom]+size[t];
    end;
    e:=ee[e].n;
  end;
end;

procedure dfsup(nom,prev:longint);
var
  e,t:longint;
begin
  e:=start[nom];
  while (e<>0) do
  begin
    t:=ee[e].t;
    if (t<>prev) then
    begin
      if (ee[e].w=1)
      then up[t]:=size[1]-size[t]
      else up[t]:=up[nom]+down[nom]-down[t];
      dfsup(t,nom);
    end;
    e:=ee[e].n;
  end;
end;

begin
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(u,v,w);
    w:=check(w);
    add(u,v,w); add(v,u,w);
  end;
  dfsdown(1,0);
  dfsup(1,0);
  ans:=0;
  for i:=1 to n do
  begin
    cur:=down[i]+up[i];
    ans:=ans+cur*(cur-1);
  end;
  writeln(ans);
end.