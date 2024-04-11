const
  lim=4000010;
var
  next,dist,used:array[1..lim] of longint;
  n,m,i,j,cnt,path,nom,rem:longint;
  c:char;

function find(x,y:longint):longint; begin exit((x-1)*m+y); end;
procedure answer(x:longint); begin writeln(x); halt; end;

procedure mode(x,y:longint);
begin
  dist[x]:=y;
  if (path<y) then begin nom:=x; path:=y; end;
end;

procedure dfs(nom:longint);
var
  i,max:longint;
begin
  used[nom]:=2;
  max:=0;
  i:=next[nom];
  if (i<>0) then
  begin
    if (used[i]=2) then answer(-1);
    if (used[i]=0) then dfs(i);
    max:=dist[i]+1;
  end;
  mode(nom,max);
  used[nom]:=1;
end;

procedure solve(nom:longint);
var
  i,max:longint;
begin
  used[nom]:=1;
  max:=0;
  i:=next[nom];
  if (i<>0) and (used[i]<>5) then
  begin
    if (used[i]=0) then solve(i);
    max:=dist[i]+1;
  end;
  mode(nom,max);
end;

begin
  readln(n,m);
  cnt:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      inc(cnt);
      read(c);
      if (c='#') then next[cnt]:=0;
      if (c='>') then next[cnt]:=find(i,j+1);
      if (c='<') then next[cnt]:=find(i,j-1);
      if (c='^') then next[cnt]:=find(i-1,j);
      if (c='v') then next[cnt]:=find(i+1,j);
    end;
    readln;
  end;
  path:=0;
  for i:=1 to cnt do if (used[i]=0) then dfs(i);
  if (path=0) then answer(0);
  fillchar(used,sizeof(used),0);
  fillchar(dist,sizeof(dist),0);
  rem:=path;
  path:=0;
  i:=nom;
  while (next[i]<>0) do
  begin
    used[i]:=5;
    i:=next[i];
  end;
  for i:=1 to cnt do if (used[i]=0) then solve(i);
  if (path=rem) then answer(rem*2) else answer(rem*2-1);
end.