const base=1000000007; m=50;
type dp=record cost,cnt:int64; end;
var
  f:array[1..2,0..m,0..m] of dp; q:array[1..3,1..100000] of longint;
  c:array[0..m,0..m] of int64; n,i,j,k1,k2,st,fn,x,y,z,k:longint;


procedure add(x,y,z:longint);
begin
  q[1,fn]:=x; q[2,fn]:=y; q[3,fn]:=z; inc(fn);
end;


procedure out(var x,y,z:longint);
begin
  x:=q[1,st]; y:=q[2,st]; z:=q[3,st]; inc(st);
end;


begin

  for i:=0 to m do c[i,0]:=1;
  for i:=1 to m do for j:=1 to m do c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod base;
  readln(n,k); k1:=0; k2:=0;
  for i:=1 to n do
  begin
    read(x);
    if x=50 then inc(k1) else inc(k2);
  end;
  for x:=1 to 2 do for y:=0 to m do for z:=0 to m do f[x,y,z].cost:=maxlongint;
  f[1,k1,k2].cost:=0; f[1,k1,k2].cnt:=1; st:=1; fn:=1; add(1,k1,k2);
  while st<>fn do
  begin
    out(x,y,z);
    for i:=0 to y do
      for j:=0 to z do
      if (i+j<>0) and (i*50+j*100<=k) and (f[x,y,z].cost+1<=f[3-x,k1-y+i,k2-z+j].cost) then
      begin
        if f[3-x,k1-y+i,k2-z+j].cost=maxlongint then add(3-x,k1-y+i,k2-z+j);
        f[3-x,k1-y+i,k2-z+j].cost:=f[x,y,z].cost+1;
        f[3-x,k1-y+i,k2-z+j].cnt:=(f[3-x,k1-y+i,k2-z+j].cnt+((f[x,y,z].cnt*c[y,i]) mod base)*c[z,j]) mod base;
      end;
  end;
  if f[2,k1,k2].cost=maxlongint then begin writeln(-1); writeln(0); end else
  begin
    writeln(f[2,k1,k2].cost);
    writeln(f[2,k1,k2].cnt);
  end;

end.