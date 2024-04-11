uses
  math;
var
  f:array[1..3,1..3,0..50] of int64;
  g:array[1..3,1..3] of int64;
  i,j,k,n,h:longint;

begin
  for i:=1 to 3 do for j:=1 to 3 do read(g[i,j]);
  read(n);
  for k:=1 to n do for i:=1 to 3 do for j:=1 to 3 do if (i<>j) then
  begin
    h:=6-i-j;
    f[i,j,k]:=min(f[i,h,k-1]+g[i,j]+f[h,j,k-1],f[i,j,k-1]+g[i,h]+f[j,i,k-1]+g[h,j]+f[i,j,k-1]);
  end;
  writeln(f[1,3,n]);
end.