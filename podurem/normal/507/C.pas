var
	f,i,kuda,n:longint;
	k,kol:int64;

function step(a,b:longint):int64;
var
	i:longint;
	c:int64;
begin
	c:=1;
	for i:=1 to b do
		c:=c*a;
step:=c;
end;
	
BEGIN
readln(n,k);
kuda:=1;
kol:=0;
for f:=1 to n do
	begin
		inc(kol);
		if (kuda=1) and (step(2,n-f+1) div 2<k) then
			begin
				for i:=0 to n-f do
					kol:=kol+step(2,i);
				k:=k-step(2,n-f+1) div 2;
			end
		else if (kuda=1) and (step(2,n-f+1) div 2>=k) then kuda:=2
		else if (kuda=2) and (step(2,n-f+1) div 2>=k) then
				for i:=0 to n-f do
					kol:=kol+step(2,i)
		else begin kuda:=1; k:=k-step(2,n-f+1) div 2; end;
	end;
writeln(kol);
END.