uses
  math;
const
  l=100;
  inf=maxlongint;
var
  q:array[1..3,1..l*l*l] of longint;
  res:array[1..2,1..l*l*l] of longint;
  f,from,too,xx,yy,zz:array[1..l,1..l,1..l] of longint;
  g:array[1..l,1..l] of char;
  n,s1,s2,s3,x,y,z,st,en,i,j,k,ans,move:longint;

procedure find(s1,s2,s3:longint;var x,y,z:longint);
var
  w:longint;
begin
  if (s1>s2) then begin w:=s1; s1:=s2; s2:=w; end;
  if (s1>s3) then begin w:=s1; s1:=s3; s3:=w; end;
  if (s2>s3) then begin w:=s2; s2:=s3; s3:=w; end;
  x:=s1;
  y:=s2;
  z:=s3;
end;

procedure update(x,y,z,i,j,k,o,p,num:longint);
begin
  if (f[x,y,z]=inf) then
  begin
    q[1,en]:=x;
    q[2,en]:=y;
    q[3,en]:=z;
    inc(en);
  end;
  if (f[x,y,z]<=num) then exit;
  f[x,y,z]:=num;
  from[x,y,z]:=o;
  too[x,y,z]:=p;
  xx[x,y,z]:=i;
  yy[x,y,z]:=j;
  zz[x,y,z]:=k;
end;

begin
  for x:=1 to l do for y:=1 to l do for z:=1 to l do f[x,y,z]:=inf;
  readln(n);
  readln(s1,s2,s3);
  for i:=1 to n do
  begin
    for j:=1 to n do read(g[i,j]);
    readln;
  end;
  find(s1,s2,s3,s1,s2,s3);
  st:=1; en:=1;
  update(s1,s2,s3,0,0,0,0,0,0);
  while (st<>en) do
  begin
    x:=q[1,st];
    y:=q[2,st];
    z:=q[3,st];
    inc(st);
    for move:=1 to n do
    begin
      if (move=x) or (move=y) or (move=z) then continue;
      if (g[x,y]=g[z,move]) then
      begin
        find(x,y,move,i,j,k);
        update(i,j,k,x,y,z,z,move,f[x,y,z]+1);
      end;
      if (g[x,z]=g[y,move]) then
      begin
        find(x,z,move,i,j,k);
        update(i,j,k,x,y,z,y,move,f[x,y,z]+1);
      end;
      if (g[y,z]=g[x,move]) then
      begin
        find(y,z,move,i,j,k);
        update(i,j,k,x,y,z,x,move,f[x,y,z]+1);
      end;
    end;
  end;
  if (f[1,2,3]=inf) then writeln(-1) else
  begin
    x:=1;
    y:=2;
    z:=3;
    ans:=f[1,2,3];
    while (ans<>0) do
    begin
      res[1,ans]:=from[x,y,z];
      res[2,ans]:=too[x,y,z];
      dec(ans);
      i:=xx[x,y,z];
      j:=yy[x,y,z];
      k:=zz[x,y,z];
      x:=i;
      y:=j;
      z:=k;
    end;
    ans:=f[1,2,3];
    writeln(ans);
    for i:=1 to ans do writeln(res[1,i],' ',res[2,i]);
  end;
end.