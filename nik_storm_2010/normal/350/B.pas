uses
  math;
type
  edges=record
    too,nxt:longint;
  end;
const
  ll=100000;
var
  ee:array[1..3*ll] of edges;
  k,a,s,into,kind,path:array[0..ll] of longint;
  bad:array[0..ll] of boolean;
  cnt,ans,n,i:longint;

procedure add(x,y:longint);
begin
  inc(cnt);
  ee[cnt].too:=y;
  ee[cnt].nxt:=s[x];
  inc(into[y]);
  s[x]:=cnt;
end;

procedure dfsfind(nom,sum:longint);
var
  e:longint;
begin
  if (kind[nom]=1) then ans:=max(ans,sum);
  e:=s[nom];
  while (e<>0) do
  begin
    dfsfind(ee[e].too,sum+1);
    e:=ee[e].nxt;
  end;
end;

procedure dfs(nom,sum:longint);
var
  e:longint;
begin
  path[sum]:=nom;
  if (kind[nom]=1) and (sum=ans) then
  begin
    writeln(ans);
    for i:=1 to sum do write(path[i],' ');
    halt;
  end;
  e:=s[nom];
  while (e<>0) do
  begin
    dfs(ee[e].too,sum+1);
    e:=ee[e].nxt;
  end;
end;

begin
  readln(n);
  for i:=1 to n do read(kind[i]);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(k[a[i]]);
  end;
  for i:=1 to n do if (k[i]>1) then bad[i]:=true;
  for i:=1 to n do
  begin
    if (a[i]=0) or (bad[i]) or (bad[a[i]]) then continue;
    add(a[i],i);
  end;
  ans:=0;
  for i:=1 to n do
  begin
    if (bad[i]) or (into[i]<>0) then continue;
    dfsfind(i,1);
  end;
  for i:=1 to n do
  begin
    if (bad[i]) or (into[i]<>0) then continue;
    dfs(i,1);
  end;
  writeln(ans);
end.