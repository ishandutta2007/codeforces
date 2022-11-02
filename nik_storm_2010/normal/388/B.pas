const
  lim=2000;
  leng=30;
var
  g:array[1..lim,1..lim] of char;
  a:array[1..lim] of longint;
  r:array[1..lim,1..lim] of longint;
  l,now:array[1..lim] of longint;
  n,k,i,j,cnt,x,ans,y,all,size,free,mnog,p1,p2,z:longint;

function next(x:longint):longint;
begin
  if (x=1) then exit(3) else exit(x+1);
end;

procedure make(x,y:longint);
begin
  g[x,y]:='Y';
  g[y,x]:='Y';
end;

procedure add;
var
  i:longint;
begin
  i:=1;
  free:=next(free);

end;

begin
for i:=1 to lim do for j:=1 to lim do g[i,j]:='N';
  free:=1;
  for i:=1 to 30 do
  begin
    if (i<>1) then make(free,next(free));
    free:=next(free);
    now[i]:=free;
  end;
  make(free,2);
  z:=free;
  p1:=1; p2:=-1;
  for i:=1 to 30 do
  begin
    make(p1,next(free));
    if (p2<>-1) then make(p2,next(free));
    x:=next(free);
    free:=next(free);
    make(p1,next(free));
    if (p2<>-1) then make(p2,next(free));
    y:=next(free);
    free:=next(free);
    p1:=x;
    p2:=y;
  end;
  readln(k);
  p1:=1; p2:=-1; cnt:=1;
  while (k>0) do
  begin
    x:=k mod 2;
    k:=k div 2;
    if (x<>0) then
    begin
      if (p1<>-1) then make(p1,now[cnt]);
      if (p2<>-1) then make(p2,now[cnt]);
    end;
    inc(cnt);
    z:=next(z);
    p1:=z;
    z:=next(z);
    p2:=z;
  end;
  writeln(1000);
  for i:=1 to 1000 do
  begin
    for j:=1 to 1000 do write(g[i,j]);
    writeln;
  end;
end.