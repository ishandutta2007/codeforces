Var
    n,i: longint;


function happy(c:longint) : boolean;
var r:longint;
 begin
  happy:=true;
   while c<>0 do
    begin
     r:=c mod 10;
      if (r<>4) and (r<>7) then happy:=false;
     c:=c div 10;
    end;
 end;


Begin

  readln(n);
   for i:=1 to n do
    if (n mod i = 0) and (happy(i)=true)
     then
      begin
       writeln('YES');
        halt;
      end;
  writeln('NO');

End.