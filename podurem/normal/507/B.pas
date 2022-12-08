var
	r,a,b,a1,b1:real;

BEGIN
readln(r,a,b,a1,b1);
a:=sqrt(sqr(a1-a)+sqr(b1-b))/2/r;
if a-trunc(a)<>0 then writeln(trunc(a+1)) else writeln(a:0:0);
END.