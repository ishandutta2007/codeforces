{ Author : Sazanovich Nikita }
{ Memory : 0.00001 megabyte }
{ Time : 5 }
var
 a,x,y : longint;



begin

  readln(a,x,y);
  if (x<=-a) or (x>=a) or (y mod a = 0)
   then
    begin
     writeln(-1);
    end
   else
    begin
     if (y<a) and (-a / 2<x) and (x<a / 2)
      then
       begin
        writeln(1);
       end
      else
       begin
        y:=y-a;
         if ((y div a + 1) mod 2 = 0) and (x=0)
          then
           begin
            writeln(-1);
           end
          else
           begin
            if ((y div a +1) mod 2 = 0)
             then
              begin
               if (x<0)
                then
                 begin
                  writeln((y div a +1) div 2 * 3);
                 end
                else
                 begin
                  writeln((y div a +1) div 2 * 3 + 1);
                 end;
              end
             else
              begin
               if (x<=(-a / 2)) or (x>=(a / 2 ))
                then
                 begin
                  writeln(-1);
                 end
                else
                 begin
                  writeln((y div a+1) div 2 * 3 + 2);
                 end;
              end;
           end;
       end;
    end;

end.