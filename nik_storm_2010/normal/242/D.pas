const
  l=300000;
type
  edges=record
    t,n:longint;
  end;
var
  ee:array[1..l] of edges;
  start,sum,bad,q:array[1..l] of longint;
  get,used:array[1..l] of boolean;
  ans,cnt,st,fn,n,m,x,y,i:longint;

procedure addedge(x,y:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

procedure add(x:longint);
begin
  used[x]:=true;
  q[fn]:=x;
  inc(fn);
end;

procedure update(x:longint);
var
  e,t:longint;
begin
  if (bad[x]<>sum[x]) then exit;
  inc(sum[x]);
  inc(ans);
  get[x]:=true; 
  e:=start[x];
  while (e<>0) do
  begin
    t:=ee[e].t;
    inc(sum[t]);
    e:=ee[e].n;
  end;
  e:=start[x];
  while (e<>0) do
  begin
    t:=ee[e].t;
    if (not used[t]) and (sum[t]=bad[t]) then add(t);
    e:=ee[e].n;
  end;
end;

begin
  read(n,m);
  for i:=1 to m do 
  begin
    read(x,y);
    addedge(x,y);
    addedge(y,x);
  end;
  for i:=1 to n do read(bad[i]);
  st:=1; fn:=1;
  for i:=1 to n do if (bad[i]=0) then add(i); 
  while (st<>fn) do
  begin
    update(q[st]);
    inc(st);
  end; 
  writeln(ans);
  for i:=1 to n do if (get[i]) then write(i,' ');
end.