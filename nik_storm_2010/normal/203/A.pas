var
  x,t,a,b,da,db,i,j,tek : longint;


begin

  readln(x,t,a,b,da,db);
   for i:=-1 to t-1 do
    for j:=-1 to t-1 do
   begin
    tek:=0;
     if i<>-1 then tek:=tek + a - (da*i);
     if j<>-1 then tek:=tek + b - (db*j);
    if tek = x then
     begin
      writeln('YES');
      halt;
     end;
   end;
  writeln('NO');

end.