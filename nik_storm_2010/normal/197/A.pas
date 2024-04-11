var
    a,b,r:longint;


begin

  readln(a,b,r);
  if (a<r*2) or (b<r*2) then writeln('Second') else writeln('First');

end.