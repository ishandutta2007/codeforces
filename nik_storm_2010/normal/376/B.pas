uses
  math;
const
  l=200;
var
  g:array[1..l,1..l] of longint;
  n,m,i,j,k,x,ans:longint;

begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(j,k,x);
    g[j,k]:=x;
  end;
  for k:=1 to n do for i:=1 to n do for j:=1 to n do if (g[i,k]>0) and (g[k,j]>0) then
  begin
    x:=min(g[i,k],g[k,j]);
    g[i,j]:=g[i,j]+x;
    g[i,k]:=g[i,k]-x;
    g[k,j]:=g[k,j]-x;
  end;
  ans:=0;
  for i:=1 to n do for j:=1 to n do ans:=ans+g[i,j];
  writeln(ans);
end.