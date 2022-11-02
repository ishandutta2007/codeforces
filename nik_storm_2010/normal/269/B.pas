uses math;
var
  k,f:array[1..5000] of longint; x:array[1..5000] of extended;
  ans,n,m,i,j:longint;


begin

  readln(n,m);
  for i:=1 to n do readln(k[i],x[i]);
  for i:=1 to n do
  begin
    f[i]:=1;
    for j:=i-1 downto 1 do
      if (k[j]<=k[i]) and (f[j]+1>f[i]) then f[i]:=f[j]+1;
    ans:=max(ans,f[i]);
  end;
  writeln(n-ans);

end.