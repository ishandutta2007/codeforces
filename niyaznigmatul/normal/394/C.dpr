var i, j, n, m, tmp, sum, k00, k01, k11 : longint;
s : array[0 .. 123456] of longint;
begin
read(n, m);
for i := 1 to n do  for j := 1 to m do begin
read(tmp);
if tmp = 0 then inc(k00);
if tmp = 1 then inc(k01);
if tmp = 10 then inc(k01);
if tmp = 11 then inc(k11);
end;
sum := k01 + 2 * k11;
sum := (sum + 2 * m - 1) div (2* m);
for i := 1 to n do begin
for j := 1 to m do begin
if k11 > 0 then begin
write('11 ');
inc(s[2 * j - 1]);
inc(s[2 * j]);
dec(k11);
continue;
end;
if k01 > 0 then begin
if s[2 * j - 1] > s[2 * j] then begin
write('01 ');
inc(s[2 * j]);
dec(k01);
continue;
end;
if s[2 * j - 1] < sum then begin
write('10 ');
inc(s[2 * j - 1]);
dec(k01);
continue;
end;
end;
dec(k00);
write('00 ');
end;
writeln;
end;
end.