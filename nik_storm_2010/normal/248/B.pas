var
    koef,tek,n,i:longint;


begin

  readln(n);
  if (n=1) or (n=2) then
    begin
      writeln(-1);
    end
      else
    begin
      if (n=3) then writeln(210) else
        begin
          tek:=50; for i:=5 to n do tek:=tek*10 mod 210;
          if tek<10 then koef:=1 else if tek<100 then koef:=2 else koef:=3;

          write(1); for i:=1 to n-(1+koef) do write(0);
          writeln(tek);
        end;
    end;

end.