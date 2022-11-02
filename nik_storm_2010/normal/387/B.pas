const
  l=2000000;
var
  a,b:array[1..l] of longint;
  ans,n,m,i,j,x:longint;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(x);
    inc(a[x]);
  end;
  for i:=1 to m do
  begin
    read(x);
    inc(b[x]);
  end;
  j:=l; ans:=0;
  for i:=l downto 1 do
  begin
    if (a[i]=0) then continue;
    while (j>=i) and (b[j]=0) do dec(j);
    if (j<i) then inc(ans) else dec(b[j]);
  end;
  writeln(ans);
end.