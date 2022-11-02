uses math; const l=100000; type edges=record t,n:longint; end;
var
  e:array[1..2*l] of edges; down,up,s:array[1..l] of longint;
  ok:array[1..l] of boolean; cnt,n,m,d,x,y,z,i:longint;


procedure add(x,y:longint);
begin
  inc(cnt);
  e[cnt].t:=y; e[cnt].n:=s[x]; s[x]:=cnt;
end;


procedure dfsdown(x,p:longint);
var i:longint;
begin
  i:=s[x];
  while (i<>0) do
  begin
    if (e[i].t<>p) then
    begin
      dfsdown(e[i].t,x);
      down[x]:=max(down[x],down[e[i].t]+1);
    end;
    i:=e[i].n;
  end;
  if (down[x]=0) then if (ok[x]) then down[x]:=0 else down[x]:=-maxlongint;
end;


procedure dfsup(x,p,m1,m2:longint);
var i:longint;
begin
  if (x=z) then up[x]:=0 else
  begin
    if (m1=down[x]) then up[x]:=m2+2 else up[x]:=m1+2;
    up[x]:=max(up[x],up[p]+1);
  end;
  i:=s[x]; m1:=-maxlongint; m2:=-maxlongint;
  while (i<>0) do
  begin
    if (e[i].t<>p) then
    begin
      if (down[e[i].t]>m1)
      then begin m2:=m1; m1:=down[e[i].t]; end else
      begin
        if (down[e[i].t]>m2) then m2:=down[e[i].t];
      end;
    end;
    i:=e[i].n;
  end;
  i:=s[x];
  while (i<>0) do
  begin
    if (e[i].t<>p) then dfsup(e[i].t,x,m1,m2);
    i:=e[i].n;
  end;
end;


begin
  readln(n,m,d);
  for i:=1 to m do
  begin
    read(z);
    ok[z]:=true;
  end;
  for i:=1 to n-1 do
  begin
    readln(x,y);
    add(x,y); add(y,x);
  end;
  dfsdown(z,0); dfsup(z,0,0,0);
  cnt:=0;
  for i:=1 to n do if (down[i]<=d) and (up[i]<=d) then inc(cnt);
  writeln(cnt);
end.