uses math;
var
  a:array[1..50] of longint; ans,n,m,i,j,w:longint;


begin
  readln(n,m);
  for i:=1 to m do read(a[i]);
  for i:=1 to m do for j:=i+1 to m do
    if (a[i]>a[j]) then begin w:=a[i]; a[i]:=a[j]; a[j]:=w; end;
  ans:=maxlongint;
  for i:=1 to m-n+1 do ans:=min(ans,a[i+n-1]-a[i]);
  writeln(ans);
end.