uses
  math;
const
  l=24;
var
  f,px,py:array[0..1 shl l] of longint;
  g:array[0..l,0..l] of longint;
  x,y,ras:array[0..l] of longint;
  path:array[1..100] of longint;
  mask,xs,ys,n,i,j,lim,nw,k:longint;

begin
  readln(xs,ys);
  readln(n);
  for i:=0 to n-1 do
  begin
    readln(x[i],y[i]);
    x[i]:=x[i]-xs;
    y[i]:=y[i]-ys;
  end;
  for i:=0 to n-1 do for j:=0 to n-1 do g[i,j]:=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
  for i:=0 to n-1 do ras[i]:=sqr(x[i])+sqr(y[i]);
  f[0]:=0;
  lim:=(1 shl n)-1;
  for mask:=1 to lim do
  begin
    f[mask]:=maxlongint;
    for i:=0 to n-1 do
    begin
      if (mask and (1 shl i)=0) then continue;
      nw:=f[mask xor (1 shl i)]+2*ras[i];
      if (f[mask]>nw) then begin f[mask]:=nw; px[mask]:=i; py[mask]:=-1; end;
    end;
    for i:=0 to n-1 do
    begin
      if (mask and (1 shl i)=0) then continue;
      for j:=i+1 to n-1 do
      begin
        if (mask and (1 shl j)=0) then continue;
        nw:=f[mask xor (1 shl i) xor (1 shl j)]+ras[i]+ras[j]+g[i,j];
        if (f[mask]>nw) then begin f[mask]:=nw; px[mask]:=i; py[mask]:=j; end;
      end;
      break;
    end;
  end;
  writeln(f[lim]);
  k:=1;
  mask:=lim;
  while (mask<>0) do
  begin
    nw:=(1 shl px[mask]);
    inc(k);
    path[k]:=px[mask]+1;
    if (py[mask]<>-1) then begin nw:=nw or (1 shl py[mask]); inc(k); path[k]:=py[mask]+1; end;
    inc(k);
    path[k]:=0;
    mask:=mask xor nw;
  end;
  for i:=k downto 1 do write(path[i],' ');
end.