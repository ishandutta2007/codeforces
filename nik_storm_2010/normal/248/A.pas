uses math;
var
    kollo,kollc,kolro,kolrc,n,x,y,i:longint;


begin

  readln(n); kollo:=0; kollc:=0; kolro:=0; kolrc:=0;
  for i:=1 to n do
    begin
      readln(x,y);
      if x=1 then inc(kollo) else inc(kollc);
      if y=1 then inc(kolro) else inc(kolrc);
    end;
  writeln(min(kollo,kollc)+min(kolro,kolrc));

end.