var
  x,y:longint;


begin
  readln(x,y);
  if (x>0) and (y>0) then
  begin
    writeln(0,' ',x+y,' ',x+y,' ',0);
    halt;
  end;
  if (x>0) and (y<0) then
  begin
    y:=-y;
    writeln(0,' ',-(x+y),' ',x+y,' ',0);
    halt;
  end;
  if (x<0) and (y>0) then
  begin
    x:=-x;
    writeln(-(x+y),' ',0,' ',0,' ',x+y);
    halt;
  end;
  if (x<0) and (y<0) then
  begin
    x:=-x; y:=-y;
    writeln(-(x+y),' ',0,' ',0,' ',-(x+y));
    halt;
  end;
end.