program storm;
var n,m,a,kol,kol1,kol2:int64;


procedure inputdata;
begin
 readln(n,m,a);
end;

procedure outputdata;
begin
 writeln(kol);
end;

begin
 inputdata; kol:=0; kol1:=0; kol2:=0;
 if n mod a = 0 then kol1:=n div a
                else kol1:=(n div a)+1;
 if m mod a = 0 then kol2:=m div a
                else kol2:=(m div a)+1;
 kol:=kol1*kol2;
 outputdata;
end.