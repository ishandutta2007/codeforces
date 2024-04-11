uses math;
 var n,m,i,j,ans:longint;


begin

  readln(n,m); ans:=0;
  for i:=0 to max(n,m) do
    for j:=0 to max(n,m) do
      if (i*i+j=n) and (i+j*j=m) then
    inc(ans);
  writeln(ans);

end.