uses
  math;
const
  l=500+10;
var
  sum,a,f:array[0..l,0..l] of longint;
  n,m,x1,y1,x2,y2,k,o,i,j,ans:longint;

begin
  readln(n,m);
  for i:=1 to n do for j:=1 to m do begin read(a[i,j]); f[i,j]:=a[i,j]; end;
  for i:=1 to n do for j:=1 to m do sum[i,j]:=sum[i-1,j]+sum[i,j-1]-sum[i-1,j-1]+a[i,j];
  ans:=-maxlongint;
  k:=3;
  while (k<=min(n,m)) do
  begin
    for x1:=1 to n-k+1 do for y1:=1 to m-k+1 do
    begin
      x2:=x1+k-1;
      y2:=y1+k-1;
      f[x1,y1]:=sum[x2,y2]+sum[x1-1,y1-1]-sum[x2,y1-1]-sum[x1-1,y2]-f[x1+1,y1+1]-a[x1+1,y1];
      ans:=max(ans,f[x1,y1]);
    end;
    k:=k+2;
  end;
  writeln(ans);
end.