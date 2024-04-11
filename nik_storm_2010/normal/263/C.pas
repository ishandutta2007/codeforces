const
  l=1000000;
type
  edges=record
    t,n:longint;
  end;
var
  ee:array[1..l] of edges;
  start,path,size:array[1..l] of longint;
  used:array[1..l] of boolean;
  n,i,x,y,cnt:longint;

procedure addedge(x,y:longint);
begin
  inc(size[x]);
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

function have(x,y:longint):boolean;
var
  e:longint;
begin
  e:=start[x];
  while (e<>0) do
  begin
    if (ee[e].t=y) then begin have:=true; exit; end;
    e:=ee[e].n;
  end;
  have:=false;
end;

procedure rec(x,nom:longint);
var
  e,t:longint;
begin
  path[nom]:=x;
  if (nom>2) and (have(path[nom-2],path[nom])=false) then exit;
  if (nom=n) then
  begin
    if (not have(path[n-1],path[1])) then exit;
    if (not have(path[n],path[2])) then exit;
    if (not have(path[n],path[1])) then exit;
    for e:=1 to n do write(path[e],' ');
    writeln;
    halt;
  end;
  e:=start[x];
  while (e<>0) do
  begin
    t:=ee[e].t;
    if (not used[t]) then
    begin
      used[t]:=true;
      rec(t,nom+1);
      used[t]:=false;
    end;
    e:=ee[e].n;
  end;
end;

begin
  readln(n);
  for i:=1 to 2*n do
  begin
    readln(x,y);
    addedge(x,y);
    addedge(y,x);
  end;
  for i:=1 to n do if (size[i]<>4) then begin writeln(-1); halt; end;
  used[1]:=true;
  rec(1,1);
  writeln(-1);
end.