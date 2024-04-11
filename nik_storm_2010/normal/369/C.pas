const
  ll=200000;
type
  edges=record
    t,w,n:longint;
  end;
var
  ee:array[1..2*ll] of edges;
  start:array[1..ll] of longint;
  ans:array[1..ll] of boolean;
  cnt,n,i,x,y,t:longint;
  good:boolean;

function dfs(nom,prev:longint):boolean;
var
  e,i:longint;
  have,now:boolean;
begin
  e:=start[nom];
  have:=false;
  while (e<>0) do
  begin
    i:=ee[e].t;
    if (i=prev) then begin e:=ee[e].n; continue; end;
    now:=dfs(i,nom);
    have:=have or now;
    e:=ee[e].n;
  end;
  if (have) then exit(true);
  e:=start[nom];
  while (e<>0) do
  begin
    i:=ee[e].t;
    if (i<>prev) then begin e:=ee[e].n; continue; end;
    if (ee[e].w=2) then
    begin
      ans[nom]:=true;
      exit(true);
    end
    else exit(false);
  end;
end;

procedure add(x,y,t:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  ee[cnt].w:=t;
  start[x]:=cnt;
end;

begin
  readln(n);
  for i:=1 to n-1 do
  begin
    readln(x,y,t);
    add(x,y,t);
    add(y,x,t);
  end;
  good:=dfs(1,-1);
  cnt:=0;
  for i:=1 to n do if (ans[i]) then inc(cnt);
  writeln(cnt);
  for i:=1 to n do if (ans[i]) then write(i,' ');
end.