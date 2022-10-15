var i,n:longint;
a,b: ansistring ;
check:array[1..10000001] of integer;
count:longint;
begin
readln(n);
readln(a);
readln(b);
for i:=1 to n do if a[i]=b[i] then check[i]:=1 else check[i]:=0;
check[n+1]:=1;
count:=0;
for i:=1 to n do if check[i]=0 then
	if (check[i+1]=0)and(a[i]<>a[i+1]) then
	begin
	count:=count+1;
	check[i]:=1;
	check[i+1]:=1;
	end
	else
	begin
	count:=count+1;
	check[i]:=1;
	end;
write(count);
end.