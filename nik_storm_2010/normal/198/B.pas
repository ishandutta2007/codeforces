const
  l=200000;
var
  q:array[1..2,1..2*l] of longint;
  dp:array[1..2,0..l] of longint;
  wall:array[1..2,0..l] of char;
  n,k,i,st,fn,nom,x:longint;

procedure add(nom,x,time:longint);
begin
  if (x>n) then begin writeln('YES'); halt; end;
  if (wall[nom,x]='X') or (x<=time) then exit;
  if (dp[nom,x]=0) then
  begin
    q[1,fn]:=nom;
    q[2,fn]:=x;
    inc(fn);
  end;
  if (dp[nom,x]=0) or (dp[nom,x]>time) then dp[nom,x]:=time;
end;

begin
  readln(n,k);
  for i:=1 to n do read(wall[1,i]);
  readln;
  for i:=1 to n do read(wall[2,i]);
  st:=1; fn:=1;
  wall[1,0]:='X'; wall[2,0]:='X';
  add(1,1,0);
  while (st<>fn) do
  begin
    nom:=q[1,st];
    x:=q[2,st];
    inc(st);
    add(nom,x+1,dp[nom,x]+1);
    add(nom,x-1,dp[nom,x]+1);
    add(3-nom,x+k,dp[nom,x]+1);
  end;
  writeln('NO');
end.