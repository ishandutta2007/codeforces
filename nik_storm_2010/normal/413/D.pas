const
  ln=2000+10;
  lm=16384;
  md=1000000000+7;
var
  f:array[0..ln,0..lm,0..1] of longint;
  a:array[1..ln] of longint;
  ans,n,k,i,j,x,was,nwas:longint;

procedure up(var x:longint);
begin
  if (x>=md) then x:=x-md;
end;

begin
  //buildgraph;
  readln(n,k);
  k:=1 shl k;
  for i:=1 to n do read(a[i]);
  f[0,0,0]:=1;
  for i:=0 to n-1 do for j:=0 to lm do for was:=0 to 1 do
  begin
    if (f[i,j,was]=0) then continue;
    if (a[i+1]=2) then
    begin
      nwas:=was;
      x:=j+2;
      if (x>=k) then nwas:=1;
      f[i+1,x,nwas]:=f[i+1,x,nwas]+f[i,j,was];
      up(f[i+1,x,nwas]);
      continue;
    end;
    if (a[i+1]=4) then
    begin
      nwas:=was;
      x:=j;
      if ((x and 2)<>0) then x:=0;
      x:=x+4;
      if (x>=k) then nwas:=1;
      f[i+1,x,nwas]:=f[i+1,x,nwas]+f[i,j,was];
      up(f[i+1,x,nwas]);
      continue;
    end;
    nwas:=was;
    x:=j+2;
    if (x>=k) then nwas:=1;
    f[i+1,x,nwas]:=f[i+1,x,nwas]+f[i,j,was];
    up(f[i+1,x,nwas]);
    nwas:=was;
    x:=j;
    if ((x and 2)<>0) then x:=0;
    x:=x+4;
    if (x>=k) then nwas:=1;
    f[i+1,x,nwas]:=f[i+1,x,nwas]+f[i,j,was];
    up(f[i+1,x,nwas]);
  end;
  ans:=0;
  for j:=0 to lm do
  begin
    ans:=ans+f[n,j,1];
    up(ans);
  end;
  writeln(ans);
end.