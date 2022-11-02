var
 a: array[1..7] of longint;
  tek,all,i: longint;


begin

  readln(all);
   for i:=1 to 7 do read(a[i]);

  tek:=1;
   while all<>0 do
    begin

     if all<=a[tek]
      then
       begin

        all:=0;

       end
      else
       begin

        all:=all-a[tek];
         inc(tek);
          if tek=8 then tek:=1;

       end;

    end;
  writeln(tek);

end.