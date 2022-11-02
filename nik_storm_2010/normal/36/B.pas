const
  l=250;
var
  a,base:array[1..l,1..l] of char;
  n,k,i,j,g:longint;

procedure build(x1,y1,x2,y2:longint);
var
  dx,dy,i,j,nx,ny,ii,jj:longint;
begin
  dx:=(x2-x1+1) div n;
  dy:=(y2-y1+1) div n;
  for i:=1 to n do for j:=1 to n do
  begin
    nx:=x1+(i-1)*dx;
    ny:=y1+(j-1)*dy;
    if (dx=1) and (dy=1) then begin a[nx,ny]:=base[i,j]; continue; end;
    if (base[i,j]='*') then
    begin
      for ii:=nx to nx+dx-1 do for jj:=ny to ny+dy-1 do a[ii,jj]:='*';
    end
    else build(nx,ny,nx+dx-1,ny+dy-1);
  end;
end;

begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n,k);
  for i:=1 to n do for j:=1 to n do
  begin
    read(base[i,j]);
    if (j=n) then readln;
  end;
  g:=1;
  for i:=1 to k do g:=g*n;
  build(1,1,g,g);
  for i:=1 to g do for j:=1 to g do
  begin
    write(a[i,j]);
    if (j=g) then writeln;
  end;
  close(input);
  close(output);
end.