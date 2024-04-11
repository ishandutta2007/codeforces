var
a:array[1..10000] of int64;
l,r:int64;
i:longint;
belakang,depan:int64;
point:int64;
posdepan,posbelakang:int64;
total:int64;

function min(a,b:int64):int64;
begin
	if (a<b) then min:=a else min:=b;
end;

begin
total:=0;
a[1]:=4;
a[2]:=7;
belakang:=1;
depan:=2;
while (a[depan]<=1000000000) do
begin
	depan:=depan+2;
	a[depan-1]:=10*a[belakang]+4;
	a[depan]:=10*a[belakang]+7;
	belakang:=belakang+1;
end;
(*for i:=1 to depan do
	writeln(a[i]);*)
readln(l,r);
point:=1;
while a[point]<l do
	inc(point);
//writeln(point);
posdepan:=l;
posbelakang:=min(a[point],r);
//writeln(posdepan,' ',posbelakang);
while posdepan<=r do
begin	
	total:=total+(posbelakang-posdepan+1)*a[point];
	posdepan:=posbelakang+1;
	point:=point+1;
	posbelakang:=min(a[point],r);
//	writeln(point);
//	writeln(posdepan,' ',posbelakang);
end;
writeln(total);
end.