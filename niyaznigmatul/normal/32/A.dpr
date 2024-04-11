uses SysUtils, Math;
var n, d, i, j, ans : integer;
a : array[0.. 1000] of integer;
begin
read(n, d);
for i := 1 to n do read(a[i]);
ans := 0;
for i := 1 to n do 
for j := 1 to n do if (i <> j) and (abs(a[i] - a[j]) <= d) then inc(ans);
writeln(ans);
end.