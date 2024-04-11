var
  edge:array[1..2,1..100000] of longint; start,a:array[1..100000] of longint;
  used:array[1..100000] of boolean; n,r1,r2,t,p,i:longint;


procedure add(a,b,i:longint);
begin
  edge[1,i]:=b; edge[2,i]:=start[a];
  start[a]:=i;
end;


procedure dfs(nom,prev:longint);
var e:longint;
begin
  used[nom]:=true; a[nom]:=prev; e:=start[nom];
  while e<>0 do
  begin
    if used[edge[1,e]]=false then dfs(edge[1,e],nom);
    e:=edge[2,e];
  end;
end;


begin

  readln(n,r1,r2); t:=1;
  for i:=1 to n-1 do
  begin
    read(p); if t=r1 then inc(t);
    add(t,p,i*2-1); add(p,t,i*2);
    inc(t);
  end;
  dfs(r2,0);
  for i:=1 to n do if i<>r2 then write(a[i],' ');

end.