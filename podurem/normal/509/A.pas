uses math;

type
	Tmas=array[1..10,1..10] of longint;

var
	a:Tmas;
	i,j,n:longint;

BEGIN
readln(n);
for i:=1 to n do
	a[1,i]:=1;
for i:=2 to n do
	for j:=1 to n do
		a[i,j]:=a[i-1,j]+a[i,max(j-1,1)];
writeln(a[n,n]);
END.