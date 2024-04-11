const size=5000;
type edge=record t,n,w:longint; end;
var
  h:array[1..size,0..size] of longint; ee:array[1..2*size] of edge; s,x,used:array[1..size] of longint;
  p,add:array[1..3,1..size] of longint; cnt,n,i,j,a,b,c:longint;


procedure dfs(nom:longint);
var e:longint;
begin
  used[nom]:=1; e:=s[nom];
  while (e<>0) do
  begin
    if (used[ee[e].t]=0) then
    begin
      p[1,ee[e].t]:=nom; p[2,ee[e].t]:=ee[e].w;
      dfs(ee[e].t);
    end;
    e:=ee[e].n;
  end;
end;


procedure modify(nom,t:longint);
var i,w:longint;
begin
  inc(h[nom,0]); i:=h[nom,0]; h[nom,i]:=t;
  while (i>1) and (x[h[nom,i]]<x[h[nom,i shr 1]]) do
  begin
    w:=h[nom,i]; h[nom,i]:=h[nom,i shr 1]; h[nom,i shr 1]:=w;
    i:=i shr 1;
  end;
end;


function del(nom:longint):longint;
var nn,i,w:longint;
begin
  del:=h[nom,1]; h[nom,1]:=h[nom,h[nom,0]]; dec(h[nom,0]); i:=1;
  while (i*2<=h[nom,0]) do
  begin
    nn:=i*2;
    if (i*2+1<=h[nom,0]) and (x[h[nom,nn]]>x[h[nom,i*2+1]]) then nn:=i*2+1;
    if (x[h[nom,i]]>x[h[nom,nn]]) then
    begin
      w:=h[nom,i]; h[nom,i]:=h[nom,nn]; h[nom,nn]:=w;
      i:=nn;
    end
    else break;
  end;
end;


procedure push(nom:longint);
var last,a:longint;
begin
  last:=p[2,nom];
  while (last<>0) and (h[nom,0]<>0) do
  begin
    a:=del(nom);
    inc(cnt); add[1,cnt]:=p[1,nom]; add[2,cnt]:=a;
    dec(last);
  end;
end;


begin
  read(n); for i:=1 to n do begin read(x[i]); modify(i,i); end;
  for i:=1 to n-1 do
  begin
    readln(a,b,c);
    ee[i*2-1].t:=b; ee[i*2-1].n:=s[a]; ee[i*2-1].w:=c; s[a]:=i*2-1;
    ee[i*2-0].t:=a; ee[i*2-0].n:=s[b]; ee[i*2-0].w:=c; s[b]:=i*2-0;
  end;
  dfs(1);
  for i:=1 to n do
  begin
    cnt:=0;
    for j:=2 to n do push(j);
    for j:=1 to cnt do
    begin
      if (add[1,j]=1) then p[3,add[2,j]]:=i else modify(add[1,j],add[2,j]);
    end;
  end;
  for i:=1 to n do write(p[3,i],' ');
end.