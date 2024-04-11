var
   c,tek,x:int64; i,t:longint;


procedure nok(a,b:int64; var c:int64);
var i,j:int64;
 begin
  i:=a; j:=b;
   while (a>0) and (b>0) do
    if a>b then a:=a mod b
   else b:=b mod a;
  c:=(i*j) div (a+b);
 end;


begin

  readln(t);
   for i:=1 to t do
    begin
     read(c);
      nok(c+1,4*c,tek);
     writeln(tek div (c+1)+1);
    end;

end.