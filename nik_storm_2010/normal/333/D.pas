var
  a,b:array[1..1000,1..1000] of longint; c:array[1..1000] of longint;
  it,n,m,i,j,l,r,t:longint;


function maybe(cur:longint):boolean;
var i,s,x,y:longint;
begin
  inc(it);
  for i:=1 to n do
  begin
    s:=0;
    for x:=1 to m do if a[i,x]>=cur then begin inc(s); c[s]:=x; end;
    for x:=1 to s do
      for y:=x+1 to s do
      if b[c[x],c[y]]=it then exit(true) else b[c[x],c[y]]:=it;
  end;
  maybe:=false;
end;


begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  l:=0; r:=round(1e9);
  while r-l>1 do
  begin
    t:=(l+r) div 2;
    if maybe(t) then l:=t else r:=t;
  end;
  if maybe(r) then writeln(r) else writeln(l);
end.