var
    n,i:longint;


begin

  readln(n);
  if (n=1) or (n=2) then
    begin
      writeln(-1);
    end
      else
    begin
      for i:=n downto 1 do write(i,' ');
    end;

end.