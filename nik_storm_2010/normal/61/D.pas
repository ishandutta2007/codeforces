uses math;
type edges=record too,nxt,wgh:longint; end;
var
  used:array[1..100000] of boolean; edge:array[1..200000] of edges;
  start:array[1..100000] of longint; ans,n,v,x,y,z:int64; i:longint;


procedure addedge(a,b,c,i:longint);
begin
  edge[i].too:=b; edge[i].wgh:=c; edge[i].nxt:=start[a];
  start[a]:=i;
end;


procedure dfs(nom,l:longint);
var e:longint;
begin
  used[nom]:=true; e:=start[nom]; v:=max(l,v);
  while e<>0 do
  begin
    if used[edge[e].too]=false then dfs(edge[e].too,l+edge[e].wgh);
    e:=edge[e].nxt;
  end;
end;


begin

  readln(n);
  for i:=1 to n-1 do
  begin
    readln(x,y,z); ans:=ans+z*2;
    addedge(x,y,z,i*2-1); addedge(y,x,z,i*2);
  end;
  dfs(1,0);
  writeln(ans-v);

end.