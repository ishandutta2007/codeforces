var
    n,i:longint;


begin

  readln(n);
  if n mod 2 = 1 then
    begin
      writeln(-1);
    end
      else
    begin
      for i:=1 to n div 2 do write(i*2,' ',i*2-1,' ');
    end;

end.