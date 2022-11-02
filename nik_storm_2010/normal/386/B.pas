var
  a:array[1..1000] of longint;
  ans,i,j,t,n,w:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  readln(t);
  for i:=1 to n do for j:=i+1 to n do if (a[i]>a[j]) then
  begin
    w:=a[i];
    a[i]:=a[j];
    a[j]:=w;
  end;
  ans:=0;
  for i:=1 to n do
  begin
    j:=i;
    while (j<=n) and (a[j]-a[i]<=t) do inc(j);
    if (j-i>ans) then ans:=j-i;
  end;
  writeln(ans);
end.