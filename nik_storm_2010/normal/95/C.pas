const
  oo=int64(maxlongint)*maxlongint;
  l=2000;
type
  edges=record t,w,n:int64; end;
var
  g:array[1..l,1..l] of int64;
  ee:array[1..2*l] of edges;
  start,path,ps,h:array[1..l] of int64;
  used:array[1..l] of boolean;
  size,cnt,n,m,x,y,a,b,c,i,j,nom,cost,leng:longint;
  cur:int64;

procedure add(x,y,z:longint);
begin
  inc(cnt);
  ee[cnt].t:=y;
  ee[cnt].w:=z;
  ee[cnt].n:=start[x];
  start[x]:=cnt;
end;

procedure swap(x,y:longint);
var
  hl:longint;
begin
  ps[h[y]]:=x; ps[h[x]]:=y;
  hl:=h[x]; h[x]:=h[y]; h[y]:=hl;
end;

procedure update(x,y:int64);
var
  i:longint;
begin
  path[x]:=y;
  i:=ps[x];
  while (i>1) and (path[h[i]]<path[h[i div 2]]) do
  begin
    swap(i,i div 2);
    i:=i div 2
  end;
end;

procedure get(var x:longint);
var
  i,nom:longint;
begin
  x:=h[1];
  swap(1,size);
  dec(size);
  i:=1;
  while (i*2<=size) do
  begin
    nom:=i*2;
    if (i*2+1<=size) and (path[h[i*2+1]]<path[h[nom]]) then nom:=i*2+1;
    if (path[h[i]]>path[h[nom]]) then
    begin
      swap(i,nom);
      i:=nom;
    end
    else break;
  end;
end;

procedure deikstra(x:longint);
var
  i,e,t,nom:longint;
begin
  size:=n;
  for i:=1 to n do begin path[i]:=oo; h[i]:=i; ps[i]:=i; end;
  update(x,0);
  while (size<>0) do
  begin
    get(nom);
    if (path[nom]=oo) then break;
    e:=start[nom];
    while (e<>0) do
    begin
      t:=ee[e].t;
      if (path[nom]+ee[e].w<path[t]) then update(t,path[nom]+ee[e].w);
      e:=ee[e].n;
    end;
  end;
  for i:=1 to n do if (path[i]<=leng) and ((g[x,i]=0) or (g[x,i]>cost)) then g[x,i]:=cost;
end;

begin
  readln(n,m);
  readln(x,y);
  for i:=1 to m do
  begin
    readln(a,b,c);
    add(a,b,c); add(b,a,c);
  end;
  for i:=1 to n do
  begin
    readln(leng,cost);
    deikstra(i);
  end;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do path[i]:=oo;
  path[x]:=0;
  for i:=1 to n do
  begin
    cur:=oo;
    for j:=1 to n do if (not used[j]) and (path[j]<cur) then
    begin
      cur:=path[j];
      nom:=j;
    end;
    if (cur=oo) then break;
    used[nom]:=true;
    for j:=1 to n do if (g[nom,j]<>0) and (path[j]>path[nom]+g[nom,j]) then path[j]:=path[nom]+g[nom,j];
  end;
  if (path[y]=oo) then writeln(-1) else writeln(path[y]);
end.