var
  prev,ans,sq,k,j,n:int64;
  i:longint;

begin
  readln(n);
  sq:=n*n;
  if (n=0) then begin writeln(1); halt; end;
  ans:=1;
  prev:=0;
  for i:=n-1 downto 0 do
  begin
    k:=i;
    k:=k*k;
    j:=prev;
    while (k+(j+1)*(j+1)<=sq) do inc(j);
    if (j=prev) then ans:=ans+2 else ans:=ans+(j-prev)*2;
    prev:=j;
  end;
  writeln(ans+ans-2);
end.