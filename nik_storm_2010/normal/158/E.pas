uses math;
var
  f:array[0..4000,0..4000] of longint; t,d:array[1..4000] of longint;
  ans,n,k,i,j:longint;


begin

  readln(n,k);
  for i:=1 to n do
  begin
    readln(t[i],d[i]);
    f[i,0]:=max(f[i-1,0]+1,t[i])+d[i]-1;
  end;
  for i:=1 to n do
    for j:=1 to k do
    f[i,j]:=min(f[i-1,j-1],max(f[i-1,j]+1,t[i])+d[i]-1);
  ans:=86400-f[n,k];
  for i:=1 to n do ans:=max(ans,t[i]-f[i-1,k]-1);
  writeln(ans);

end.