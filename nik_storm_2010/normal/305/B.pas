var
    a,b,n,x,c:int64; i:longint;


begin

  readln(a,b); readln(n);
  for i:=1 to n do
    begin
      read(x); if (b=0) or (a/b<x) then begin writeln('NO'); halt; end;
      c:=a-x*b; a:=b; b:=c;
    end;
  if b=0 then writeln('YES') else writeln('NO');

end.