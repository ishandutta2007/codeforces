type dp=record x,y,z:longint; end;
var
  f:array[1..1000,1..10,1..10] of dp; q:array[1..3,1..1000000] of longint;
  a:array[1..1000] of longint; st,fn,i,j,k,m,xx,yy,l,x,y,z:longint; s:string;


procedure addq(x,y,z:longint);
begin
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z;
  inc(fn);
end;


procedure outq(var x,y,z:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st];
  inc(st);
end;


begin
  for i:=1 to 1000 do for j:=1 to 10 do for k:=1 to 10 do f[i,j,k].x:=-1;
  readln(s); readln(m);
  st:=1; fn:=1;
  for i:=1 to 10 do
  begin
    if (s[i]='0') then continue;
    addq(1,i,i);
    f[1,i,i].x:=0;
    f[1,i,i].y:=0;
    f[1,i,i].z:=0;
  end;
  while (st<>fn) do
  begin
    outq(i,j,k); if (i=m) then continue;
    for xx:=1 to 10 do
    begin
      if (s[xx]='0') then continue;
      if (xx>j) and (xx<>k) then
      begin
        if (f[i+1,xx-j,xx].x=-1) then
        begin
          addq(i+1,xx-j,xx);
          f[i+1,xx-j,xx].x:=i;
          f[i+1,xx-j,xx].y:=j;
          f[i+1,xx-j,xx].z:=k;
        end;
      end;
    end;
  end;
  x:=-1; y:=-1; z:=-1;
  for xx:=1 to 10 do
    for yy:=1 to 10 do
    if (f[m,xx,yy].x<>-1) then
    begin
      x:=m; y:=xx; z:=yy;
      break;
    end;
  if (x=-1) then writeln('NO') else
  begin
    writeln('YES'); l:=m;
    while (l<>0) do
    begin
      a[l]:=z; dec(l);
      i:=f[x,y,z].x;
      j:=f[x,y,z].y;
      k:=f[x,y,z].z;
      x:=i; y:=j; z:=k;
    end;
    for i:=1 to m do write(a[i],' ');
  end;
end.