uses math;
var
  g:array[1..300,1..300] of int64; n,m,i,j,x,y,z:longint;


procedure modify(k:longint);
var i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to n do
    if g[i,k]+g[k,j]<g[i,j] then g[i,j]:=g[i,k]+g[k,j];
end;


function sum:int64;
var i,j:longint; res:int64;
begin
  res:=0;
  for i:=1 to n do for j:=i to n do res:=res+g[i,j];
  sum:=res;
end;


begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do read(g[i,j]);
    readln;
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    g[x,y]:=min(g[x,y],z); g[y,x]:=min(g[y,x],z);
    modify(x); modify(y);
    write(sum,' ');
  end;
end.