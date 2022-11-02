var
  fx,fy:array[0..1000000,'a'..'z'] of longint;
  dx,dy,nod,ans,all,a,b:int64;
  x,y:ansistring;
  c:char;
  i:longint;

function gcd(x,y:int64):int64;
begin
  if (y=0) then exit(x);
  gcd:=gcd(y,x mod y);
end;

begin
  readln(a,b);
  readln(x);
  readln(y);
  dx:=length(x);
  dy:=length(y);
  nod:=gcd(dx,dy);
  for i:=1 to dx do inc(fx[i mod nod][x[i]]);
  for i:=1 to dy do inc(fy[i mod nod][y[i]]);
  all:=dx*a;
  for i:=0 to nod-1 do for c:='a' to 'z' do ans:=ans+int64(fx[i][c])*int64(fy[i][c]);
  ans:=all-ans*(all div (dx*dy div nod));
  writeln(ans);
end.