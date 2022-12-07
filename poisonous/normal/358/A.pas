var a:array[1..2000] of longint;
b,c,d,e:longint;
begin
read(b);
for c:=1 to b do
read(a[c]);
for c:=1 to b-1 do
for d:=c+2to b-1 do
if a[c+1]>a[c] then
if a[d+1]>a[d] then
if ((a[c]<a[d+1]) and (a[c]>a[d]) and (a[c+1]>a[d+1])) or ((a[c+1]<a[d+1]) and (a[c+1]>a[d]) and (a[c]<a[d])) then
begin
writeln('yes');
halt;
end else e:=e else
if (a[c]>a[d+1]) and (a[c]<a[d]) and (a[c+1]>a[d]) or ((a[c+1]>a[d+1]) and (a[c+1]<a[d]) and (a[c]<a[d+1])) then
begin
writeln('yes');
halt;
end else e:=e else
if a[d+1]>a[d] then
if (a[c+1]<a[d+1]) and (a[c+1]>a[d]) and (a[c]>a[d+1]) or ((a[c]<a[d+1]) and (a[c]>a[d]) and (a[c+1]<a[d])) then
begin
writeln('yes');
halt;
end else e:=e else
if (a[c+1]>a[d+1]) and (a[c+1]<a[d]) and (a[c]>a[d]) or ((a[c]>a[d+1]) and (a[c]<a[d]) and (a[c+1]<a[d+1]))then
begin
writeln('yes');
halt;
end else e:=e;
writeln('no');
end.