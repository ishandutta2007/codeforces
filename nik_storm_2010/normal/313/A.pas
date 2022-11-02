var
    ans,c1,c2,n:longint;


begin

  readln(n);
  if n>0 then writeln(n) else
  begin
    n:=n*(-1);
    c1:=n mod 10; c2:=(n mod 100) div 10;
    if c1>c2 then ans:=n div 100*10+c2 else ans:=n div 100*10+c1;
    writeln(-ans);
  end;

end.