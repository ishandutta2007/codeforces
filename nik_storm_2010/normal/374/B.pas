const
  l=200000;
var
  a:array[1..l] of longint;
  ans:int64;
  i,j,d,code:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do val(s[i],a[i],code);
  ans:=1;
  i:=1;
  while (i<=d) do
  begin
    if (a[i]=9) then begin inc(i); continue; end;
    j:=i+1;
    while (j<=d) and (a[j]+a[j-1]=9) do inc(j);
    if (odd(j-i)) then ans:=ans*((j-i+1) div 2);
    i:=j;
  end;
  writeln(ans);
end.