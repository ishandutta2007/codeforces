var
  edge:array[1..2,1..200000] of int64; start,v:array[1..100000] of int64;
  used:array[1..100000] of boolean; k1,k2,x,y:int64; n,i:longint;


procedure addedge(a,b,nom:longint);
begin
  edge[1,nom]:=b; edge[2,nom]:=start[a];
  start[a]:=nom;
end;


procedure dfs(nom:int64; var k1,k2:int64);
var e,x,y:int64;
begin
  k1:=0; k2:=0; e:=start[nom]; used[nom]:=true;
  while e<>0 do
  begin
    if used[edge[1,e]]=false then
    begin
      dfs(edge[1,e],x,y);
      if x>k1 then begin v[nom]:=v[nom]-(x-k1); k1:=x; end;
      if y>k2 then begin v[nom]:=v[nom]+(y-k2); k2:=y; end;
    end;
    e:=edge[2,e];
  end;
  if v[nom]>0 then k1:=k1+abs(v[nom]);
  if v[nom]<0 then k2:=k2+abs(v[nom]);
end;


begin

  readln(n);
  for i:=1 to n-1 do
    begin
      readln(x,y);
      addedge(x,y,i*2-1); addedge(y,x,i*2);
    end;
  for i:=1 to n do read(v[i]);
  dfs(1,k1,k2); writeln(k1+k2);

end.