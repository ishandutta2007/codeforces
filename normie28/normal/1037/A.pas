var a,i,count:longint;
begin
readln(a);
i:=2;
count:=1;
while (i-1<a) do
begin
i:=i*2;
count:=count+1;
end;
write(count);
end.