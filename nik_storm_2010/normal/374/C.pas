uses
  math;
const
  dx:array[1..4] of longint=(+1,-1,0,0);
  dy:array[1..4] of longint=(0,0,+1,-1);
  cur:array[1..4] of char=('D','I','M','A');
  nxt:array[1..4] of char=('I','M','A','D');
  l=1010;
type
  edges=record
    t,n:longint;
  end;
var
  a:array[0..l,0..l] of char;
  used:array[0..l,0..l] of boolean;
  was:array[1..l*l] of byte;
  ee:array[1..25*l*l] of edges;
  start,dp:array[1..l*l] of longint;
  size,ans,n,m,i,j:longint;

procedure add(x,y:longint);
begin
  inc(size);
  ee[size].t:=y;
  ee[size].n:=start[x];
  start[x]:=size;
end;

function find(x,y,state:longint):boolean;
var
  nx,ny,i:longint;
  res:boolean;
begin
  if (state=4) then begin find:=true; exit; end;
  res:=false;
  for i:=1 to 4 do
  begin
    nx:=x+dx[i]; ny:=y+dy[i];
    if (a[nx,ny]=nxt[state]) then res:=res or find(nx,ny,state+1);
  end;
  find:=res;
end;

procedure build(x,y,state,from:longint);
var
  nx,ny,i:longint;
begin
  if (state=5) then
  begin
    if (used[x,y]) then add(from,(x-1)*m+y);
    exit;
  end;
  for i:=1 to 4 do
  begin
    nx:=x+dx[i]; ny:=y+dy[i];
    if (a[nx,ny]=nxt[state]) then build(nx,ny,state+1,from);
  end;
end;

function count(nom:longint):longint;
var
  e:longint;
begin
  if (was[nom]=1) then begin writeln('Poor Inna!'); halt; end;
  if (dp[nom]<>-1) then begin count:=dp[nom]; exit; end;
  dp[nom]:=0;
  was[nom]:=1;
  e:=start[nom];
  while (e<>0) do
  begin
    dp[nom]:=max(dp[nom],count(ee[e].t));
    e:=ee[e].n;
  end;
  inc(dp[nom]);
  was[nom]:=2;
  count:=dp[nom];
end;

begin
  readln(n,m);
  for i:=1 to n do for j:=1 to m do
  begin
    read(a[i,j]);
    if (j=m) then readln;
  end;
  for i:=1 to n do for j:=1 to m do if (a[i,j]='D') then used[i,j]:=find(i,j,1);
  for i:=1 to n do for j:=1 to m do build(i,j,1,(i-1)*m+j);
  for i:=1 to n*m do dp[i]:=-1;
  ans:=-1;
  for i:=1 to n do for j:=1 to m do if (used[i,j]) then ans:=max(ans,count((i-1)*m+j));
  if (ans=-1) then writeln('Poor Dima!') else writeln(ans);
end.