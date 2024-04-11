var
  edge:array[1..2,1..200000] of longint; start,q:array[1..100000] of longint;
  used:array[1..100000] of boolean; n,m,k,l,a,b,i:longint;


procedure add(a,b,i:longint);
begin
  edge[1,i]:=b; edge[2,i]:=start[a];
  start[a]:=i;
end;


function have(i,j:longint):boolean;
var e:longint;
begin
  e:=start[i]; have:=false;
  while e<>0 do
  begin
    if edge[1,e]=j then exit(true);
    e:=edge[2,e];
  end;
end;


procedure dfs(nom:longint);
var cnt,e,i:longint;
begin
  e:=start[nom]; used[nom]:=true;
  inc(l); q[l]:=nom; cnt:=0;
  while e<>0 do
  begin
    if used[edge[1,e]]=false then begin dfs(edge[1,e]); inc(cnt); end;
    e:=edge[2,e];
  end;
  if cnt=0 then
  begin
    for e:=1 to l do if have(q[e],q[l])=true then
    begin
      writeln(l-e+1); for i:=e to l do write(q[i],' ');
      halt;
    end;
  end;
end;


begin

  readln(n,m,k);
  for i:=1 to m do
  begin
    readln(a,b);
    add(a,b,i*2-1); add(b,a,i*2);
  end;
  dfs(1);

end.