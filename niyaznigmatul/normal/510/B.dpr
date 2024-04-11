var n, m, i, j, x, y, dx, dy, v, u : longint;
c : array[0 .. 1234, 0 .. 1234] of char;
p : array[0 .. 12345] of longint;
function get(x : longint) : longint;
begin
if x <> p[x] then p[x] := get(p[x]);
result := p[x];
end;

var
ch : char;
begin
readln(n, m);
for i := 1 to n do begin
for j := 1 to m do begin
read(ch);
while ord(ch) <= 32 do read(ch);
c[i][j] := ch;
end;
end;
for i := 1 to n * m do p[i] := i;
for i := 1 to n do
for j := 1 to m do begin
for dx := 0 to 1 do begin
for dy := 0 to 1 do begin
x := i + dx;
y := j + dy;
if (dx + dy <> 1) or (x < 1) or (x > n) or (y < 1) or (y > m) or (c[x][y] <> c[i][j]) then continue;
v := (i - 1) * m + j;
u := (x - 1) * m + y;
if get(v) = get(u) then begin
writeln('Yes');
halt(0);
end;
p[get(v)] := get(u);
end;
end;
end;
writeln('No');
end.