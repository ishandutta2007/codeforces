uses math;
var
 a,b,x,y,koef:int64;


procedure nod;
var a,b,n:int64;
 begin
  a:=x; b:=y;
   while (a<>0) and (b<>0) do
    if a>b then a:=a mod b else b:=b mod a;
   n:=a+b;
  x:=x div n; y:=y div n;
 end;


begin

  readln(a,b,x,y);
   nod;
    if (a div x = 0) or (b div y = 0)
     then
      begin
       writeln(0,' ',0);
      end
     else
      begin
       koef:=min(a div x,b div y);
        writeln(x*koef,' ',y*koef);
      end;

end.