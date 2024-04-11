var
     path:array[1..2,1..200000] of longint; edge:array[1..3,1..400000] of longint; used:array[1..200000] of boolean;
      start:array[1..200000] of longint; answer,kol,a,b,n,i:longint;


procedure addedge(a,b,nom,rev:longint);
begin
  edge[1,nom]:=b; edge[2,nom]:=start[a]; edge[3,nom]:=rev;
  start[a]:=nom;
end;


procedure dfs(nom:longint);
var e:longint;
begin
  used[nom]:=true; e:=start[nom];
  while e<>0 do
    begin
      if used[edge[1,e]]=false then
        begin
          if edge[3,e]=1 then inc(path[1,1]) else inc(path[2,1]);
          dfs(edge[1,e]);
        end;
      e:=edge[2,e];
    end;
end;


procedure dfssave(nom:longint);
var e:longint;
begin
  used[nom]:=true; e:=start[nom];
  while e<>0 do
    begin
      if used[edge[1,e]]=false then
        begin
          if edge[3,e]=1 then
            begin
              path[1,edge[1,e]]:=path[1,nom]-1;
              path[2,edge[1,e]]:=path[2,nom]+1;
            end
              else
            begin
              path[1,edge[1,e]]:=path[1,nom]+1;
              path[2,edge[1,e]]:=path[2,nom]-1;
            end;
          dfssave(edge[1,e]);
        end;
      e:=edge[2,e];
    end;
end;


begin

  readln(n);
  for i:=1 to n-1 do
    begin
      readln(a,b);
      addedge(a,b,i*2-1,1); addedge(b,a,i*2,0);
    end;
  dfs(1); fillchar(used,sizeof(used),false);
  dfssave(1); answer:=maxlongint; kol:=0;
  for i:=1 to n do
    if path[2,i]<=answer then
    begin
      if path[2,i]=answer then inc(kol) else
        begin
          answer:=path[2,i];
          kol:=1;
        end;
    end;
  writeln(answer);
  for i:=1 to n do
    if path[2,i]=answer then write(i,' ');

end.