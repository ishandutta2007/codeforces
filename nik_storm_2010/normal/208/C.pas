type point=record l,c:int64; end; const ll=100;
var
  g:array[1..ll,1..ll] of longint; f:array[1..ll,1..ll] of point; q:array[1..ll] of longint;
  n,m,i,x,y:longint; sum:int64; ans:extended;


procedure find(nom:longint);
var s,e,x,i:longint;
begin
  for i:=1 to n do begin f[nom,i].l:=maxlongint; f[nom,i].c:=0; end;
  s:=1; e:=2; q[1]:=nom; f[nom,nom].l:=0; f[nom,nom].c:=1;
  while (s<>e) do
  begin
    x:=q[s]; inc(s);
    for i:=1 to n do if (g[x,i]=1) then
    begin
      if (f[nom,x].l+1=f[nom,i].l) then f[nom,i].c:=f[nom,i].c+f[nom,x].c;
      if (f[nom,x].l+1<f[nom,i].l) then
      begin
        f[nom,i].l:=f[nom,x].l+1; f[nom,i].c:=f[nom,x].c;
        q[e]:=i; inc(e);
      end;
    end;
  end;
end;


begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y);
    g[x,y]:=1; g[y,x]:=1;
  end;
  for i:=1 to n do find(i);
  ans:=1;
  for i:=2 to n-1 do
  begin
    sum:=0;
    for x:=1 to n do
      for y:=1 to n do
      if (x<>i) and (x<>y) and (y<>i) and (g[x,i]=1) and (g[i,y]=1) then
      begin
        if (f[1,x].l+2+f[y,n].l=f[1,n].l) then sum:=sum+f[1,x].c*f[y,n].c*2;
      end;
    if (ans<sum/f[1,n].c) then ans:=sum/f[1,n].c;
  end;
  writeln(ans:0:6);
end.