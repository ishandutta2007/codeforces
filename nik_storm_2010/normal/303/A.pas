var
     n,i:longint;


begin

  readln(n);
  if (n mod 2=0) then writeln(-1) else
    begin
      for i:=1 to n do write(i-1,' '); writeln;
      for i:=1 to n do write(i-1,' '); writeln;
      for i:=1 to n do write((i-1+i-1) mod n,' ');
    end;

end.