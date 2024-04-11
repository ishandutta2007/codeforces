const max=200000;
var
    edge:array[1..3,1..max] of int64; heap,p:array[1..max] of int64; path,prev,st:array[1..max] of int64;
      kol,answer,start,finish,n,m,a,b,c:int64; i:longint;


procedure addedge(a,b,c,i:int64);
begin
  edge[1,i]:=b; edge[2,i]:=c; edge[3,i]:=st[a];
  st[a]:=i;
end;


procedure swap(i,j:int64);
var tmp:int64;
begin
  tmp:=heap[i]; heap[i]:=heap[j]; heap[j]:=tmp;
  p[heap[i]]:=i; p[heap[j]]:=j;
end;


procedure createheap;
var i:longint;
begin
  heap[1]:=start; p[start]:=1; kol:=1;
  for i:=1 to n do
    if i<>start then
    begin
      inc(kol);
      heap[kol]:=i; p[i]:=kol;
    end;
end;


function extract:int64;
var min,nom,i:int64;
begin
  extract:=heap[1]; swap(1,kol); dec(kol); i:=1;
  while (i*2<=kol) do
    begin
      min:=path[heap[i*2]]; nom:=i*2;
      if (i*2+1<=kol) and (path[heap[i*2+1]]<min) then
        begin
          min:=path[heap[i*2+1]];
          nom:=i*2+1;
        end;
      if path[heap[i]]>min then
        begin
          swap(i,nom);
          i:=nom;
        end
        else break;
    end;
end;


procedure update(tek:int64);
var i:int64;
begin
  i:=p[tek];
  while (i>1) and (path[heap[i]]<path[heap[i div 2]]) do
    begin
      swap(i,i div 2);
      i:=i div 2;
    end;
end;


procedure dijkstra(start:int64);
var e,nom:int64; i:longint;
begin
  for i:=1 to n do path[i]:=maxlongint*maxlongint;
  path[start]:=0; createheap;
  for i:=1 to n do
    begin
      nom:=extract; e:=st[nom];
      while e<>0 do
        begin
          if path[edge[1,e]]>path[nom]+edge[2,e] then
            begin
              path[edge[1,e]]:=path[nom]+edge[2,e]; prev[edge[1,e]]:=nom;
              update(edge[1,e]);
            end;
          e:=edge[3,e];
        end;
    end;
  if path[finish]=maxlongint*maxlongint then answer:=-1 else answer:=path[finish];
end;


procedure outputdata;
var e:int64;
begin
  if answer=-1 then writeln(-1) else
    begin
      e:=finish;
      while e<>0 do
        begin
          write(e,' '); e:=prev[e];
        end;
    end;
end;


begin

  readln(n,m); start:=n; finish:=1;
  for i:=1 to m do
    begin
      readln(a,b,c);
      addedge(a,b,c,i*2-1); addedge(b,a,c,i*2);
    end;
  dijkstra(start); outputdata;

end.