var
  n,i,j,tek,a:longint;


begin

  readln(n);

   i:=0;
    while i*4<=n do
     begin
      tek:=n-i*4;
       if tek mod 7 = 0
        then
         begin
          j:=tek div 7;
           for a:=1 to i do write(4);
           for a:=1 to j do write(7);
          halt;
         end;
      inc(i);
     end;

  writeln(-1);

end.