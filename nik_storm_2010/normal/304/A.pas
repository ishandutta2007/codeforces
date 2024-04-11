var
    ans,n,i,j,x:longint;


begin

  readln(n); ans:=0;
  for i:=1 to n do
    for j:=i to n do
    begin
      x:=round(sqrt(sqr(i)+sqr(j)));
      if (x<=n) and (i*i+j*j=x*x) then inc(ans);
    end;
  writeln(ans);

end.