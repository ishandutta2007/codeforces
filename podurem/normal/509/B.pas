type
	Tmas=array[1..100] of longint;
	
var
	a:Tmas;
	n,k,k1,i,j,max,min:longint;
	
BEGIN
readln(n,k);
read(a[1]);
min:=a[1];
max:=a[1];
for i:=2 to n do
	begin
		read(a[i]);
		if a[i]<min then min:=a[i];
		if max<a[i] then max:=a[i];
	end;
if k<max-min then writeln('NO')
	else
		begin
			writeln('YES');
			for i:=1 to n do
				begin
					k1:=0;
					for j:=1 to a[i] do
						begin
							inc(k1);
							if k1 mod k=0 then write(k,' ')
								else write(k1 mod k,' ');
						end;
					writeln;
				end;
		end;
END.