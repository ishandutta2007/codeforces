var
	ans,x,a,b,n : int64;

function power (T,P:int64):int64;
var
	i:integer;
	res:int64;
begin
	res:=1;
	for i:=1 to p do res:=res*t;
	exit (res);
end;

begin
	ans := -maxlongint;
	readln (A,B,n);
	if (n = 1) then
		begin
			if b mod a <> 0 then writeln ('No solution') else writeln (b div a);
			halt;
		end;
	x:=80;
	while x>=-80 do
		begin
			if a*power (x,n) = B then
				begin
					ans := x;
					break;
				end;
			dec (x);
		end;
	if ans = -maxlongint then writeln ('No solution') else writeln (ans);
end.