uses math; const maxn=100000;
type edges=record t,w,n:longint; end;
var
  a:array[1..3,1..maxn] of longint; ee:array[1..maxn*2] of edges;
  s,d,h,p:array[0..maxn] of longint; ans,cnt,st,n,m,i,l,x,y,z:longint;


procedure add(x,y,z:longint);
begin
  inc(cnt);
  ee[cnt].t:=y; ee[cnt].w:=z; ee[cnt].n:=s[x];
  s[x]:=cnt;
end;


procedure swap(i,j:longint);
var w:longint;
begin
  p[h[i]]:=j; p[h[j]]:=i;
  w:=h[i]; h[i]:=h[j]; h[j]:=w;
end;


procedure del(var x:longint);
var nom,i:longint;
begin
  x:=h[1]; swap(1,cnt); dec(cnt); i:=1;
  while (i*2<=cnt) do
  begin
    nom:=i*2;
    if (i*2+1<=cnt) and (d[h[nom]]>d[h[i*2+1]]) then nom:=i*2+1;
    if (d[h[i]]>d[h[nom]]) then begin swap(i,nom); i:=nom; end else break;
  end;
end;


procedure modify(x,c:longint);
var nom,i:longint;
begin
  d[x]:=c; i:=p[x];
  while (i>1) and (d[h[i]]<d[h[i div 2]]) do
  begin
    swap(i,i div 2); i:=i div 2;
  end;
end;


procedure deikstra;
var nom,i,j:longint;
begin
  for i:=1 to n do begin h[i]:=i; p[i]:=i; d[i]:=maxlongint; end;
  modify(st,0); cnt:=n;
  while (cnt<>0) do
  begin
    del(nom); j:=s[nom];
    while (j<>0) do
    begin
      if (d[nom]+ee[j].w<d[ee[j].t]) then modify(ee[j].t,d[nom]+ee[j].w);
      j:=ee[j].n;
    end;
  end;
end;


begin
  readln(n,m,st);
  for i:=1 to m do
  begin
    readln(x,y,z);
    add(x,y,z); add(y,x,z);
    a[1,i]:=x; a[2,i]:=y; a[3,i]:=z;
  end;
  readln(l);
  deikstra;
  for i:=1 to n do if (d[i]=l) then inc(ans);
  for i:=1 to m do
  begin
    if (d[a[1,i]]>=l) then x:=-1 else
    begin
      x:=l-d[a[1,i]];
      if (x>=a[3,i]) or (d[a[2,i]]+a[3,i]-x<d[a[1,i]]+x) then x:=-1;
    end;
    if (d[a[2,i]]>=l) then y:=-1 else
    begin
      y:=l-d[a[2,i]];
      if (y>=a[3,i]) or (d[a[1,i]]+a[3,i]-y<d[a[2,i]]+y) then y:=-1;
    end;
    if (x<>-1) then inc(ans);
    if (y<>-1) then inc(ans);
    if (x<>-1) and (y<>-1) and (x+y=a[3,i]) then dec(ans);
  end;
  writeln(ans);
end.