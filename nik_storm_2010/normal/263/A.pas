var
    i,j,c:longint;


begin

  for i:=1 to 5 do
    begin
      for j:=1 to 5 do
        begin
          read(c);
          if c=1 then
            begin
            writeln(abs(3-i)+abs(3-j)); halt;
          end;
        end;
    end;

end.