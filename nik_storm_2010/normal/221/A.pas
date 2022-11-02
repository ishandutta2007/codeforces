var
     n,i:longint;


begin

  readln(n);
  if n = 1 then
    begin
      writeln(1);
    end
      else
    begin
      write(n,' ',1);
      for i:=2 to n-1 do write(' ',i);
    end;

end.