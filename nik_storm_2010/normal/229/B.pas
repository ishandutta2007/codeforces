type edges=record t,n,w:longint; end; const maxn=100000;
var
  ee:array[0..2*maxn] of edges; s,d,h,p:array[0..maxn] of longint;
  g:array[1..2,0..maxn] of array of longint; size,n,m,x,y,z,i:longint;


procedure add(x,y,z:longint);
begin
  inc(size);
  ee[size].t:=y; ee[size].w:=z; ee[size].n:=s[x];
  s[x]:=size;
end;


procedure swap(i,j:longint);
var z:longint;
begin
  p[h[i]]:=j; p[h[j]]:=i;
  z:=h[i]; h[i]:=h[j]; h[j]:=z;
end;


procedure modify(nom,x:longint);
var i:longint;
begin
  d[nom]:=x; i:=p[nom];
  while (i>1) and (d[h[i]]<d[h[i div 2]]) do
  begin
    swap(i,i div 2); i:=i div 2;
  end;
end;


procedure del(var x:longint);
var i,nom:longint;
begin
  x:=h[1]; swap(1,size); dec(size); i:=1;
  while (i*2<=size) do
  begin
    nom:=i*2;
    if (i*2+1<=size) and (d[h[nom]]>d[h[i*2+1]]) then nom:=i*2+1;
    if (d[h[i]]>d[h[nom]]) then begin swap(i,nom); i:=nom; end else break;
  end;
end;


function ras(nom,x:longint):longint;
var l,r,m:longint;
begin
  if (g[1,nom,0]=0) then exit(x);
  l:=1; r:=g[1,nom,0];
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (x<g[1,nom,m]) then r:=m else l:=m;
  end;
  ras:=x;
  if (g[1,nom,l]<=x) and (x<=g[2,nom,l]) then ras:=g[2,nom,l]+1;
  if (g[1,nom,r]<=x) and (x<=g[2,nom,r]) then ras:=g[2,nom,r]+1;
end;


procedure deikstra;
var nom,x,i,j:longint;
begin
  for i:=1 to n do begin h[i]:=i; p[i]:=i; d[i]:=maxlongint; end;
  size:=n; d[1]:=ras(1,0);
  while (size<>0) do
  begin
    del(nom); if (d[nom]=maxlongint) then exit;
    j:=s[nom];
    while (j<>0) do
    begin
      x:=ras(ee[j].t,d[nom]+ee[j].w);
      if (x<d[ee[j].t]) then modify(ee[j].t,x);
      j:=ee[j].n;
    end;
  end;
end;


begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    add(x,y,z); add(y,x,z);
  end;
  for i:=1 to n do
  begin
    read(x); setlength(g[1,i],x+1); setlength(g[2,i],x+1);
    g[1,i,0]:=x;
    for y:=1 to x do read(g[1,i,y]);
    z:=1;
    if (g[1,i,0]=0) then continue;
    g[2,i,1]:=g[1,i,1];
    for y:=2 to x do
      if (g[1,i,y]=g[2,i,z]+1) then g[2,i,z]:=g[1,i,y] else
      begin
        inc(z);
        g[1,i,z]:=g[1,i,y];
        g[2,i,z]:=g[1,i,y];
      end;
    g[1,i,0]:=z;
    readln;
  end;
  g[1,n,0]:=0;
  deikstra;
  if (d[n]=maxlongint) then write(-1) else write(d[n]);
end.