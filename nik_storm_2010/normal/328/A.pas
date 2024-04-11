var
  a,b,c,d:longint;


begin

  readln(a,b,c,d);
  if (b-a=c-b) and (c-b=d-c) then writeln(d+b-a) else
  if (b/a=c/b) and (c/b=d/c) and (frac(d*b/a)=0) then writeln(trunc(d*b/a)) else
  writeln(42);

end.