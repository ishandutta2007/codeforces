var
    n,x,i:longint; c1,c2:char;


begin

  readln(n); x:=0;
  for i:=1 to n do
    begin
      read(c1); readln(c2);
      if (c1='+') or (c2='+') then inc(x) else dec(x);
    end;
  writeln(x);

end.