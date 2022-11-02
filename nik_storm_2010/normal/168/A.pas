var
  n,x,y,need : longint;


begin

  readln(n,x,y);
   if frac(n*y/100) = 0 then need:=trunc(n*y/100) else need:=trunc(n*y/100) + 1;
 if x >= need
  then
   begin
    writeln(0);
   end
  else
   begin
    writeln(need-x);
   end;

end.