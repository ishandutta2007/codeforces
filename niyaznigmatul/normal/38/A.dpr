var n, a, b, i, ans: integer;
ar: array[0..100] of integer;
begin
read(n);
for i := 1 to n - 1 do read(ar[i]);
read(a, b);
ans := 0;
for i := a to b - 1 do ans := ans + ar[i];
writeln(ans);
end.