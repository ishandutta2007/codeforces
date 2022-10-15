{$R-,S-,Q-,O+, I-}
var 
ok : boolean;
n, m, i : longint;
x, y, px, py : array[0 .. 123456] of extended;
x0, y0, optx,cur, sx, sy, sxy, sx2, sy2, cx, cy, vx, vy, best, ans, len, dx, dy : extended;
begin
read(n);
for i := 1 to n do begin
read(x[i], y[i]);
end;
sx := 0;
sy := 0;
sxy := 0;
sx2 := 0;
sy2 := 0;

for i := 1 to n do begin
sx := sx + x[i];
sy := sy + y[i];
sxy := sxy + x[i] * y[i];
sx2 := sx2 + x[i] * x[i];
sy2 := sy2 + y[i] * y[i];
end;
cx := sx / n;
cy := sy / n;
read(m);
for i := 1 to m do begin
read(px[i], py[i]);
end;
px[m + 1] := px[1];
py[m + 1] := py[1];
ok := true;
for i := 1 to m do begin

if ((px[i] - cx) * (py[i + 1] - cy) - (px[i + 1] - cx) * (py[i] - cy)) > 0 then ok := false;
end;
if not ok then begin
best := 1e30;
for i := 1 to m do begin
x0 := px[i];
y0 := py[i];
vx := px[i + 1] - px[i];
vy := py[i + 1] - py[i];
len := sqrt(vx * vx + vy * vy);
vx := vx / len;
vy := vy  /len;
cur := 0;
cur := cur + vy * vy * (sx2 - 2 * sx * x0 + n * x0 * x0);
cur := cur + vx * vx * (sy2 - sy * y0 * 2 + n * y0 * y0);
cur := cur - vx * vy * 2 * (sxy - sx * y0 - sy * x0 + n * x0 * y0);
optx := sx * vx - n * x0 * vx + sy * vy - n * vy * y0;
optx := optx / n;
if optx < 0 then optx := 0;
if optx > len then optx := len;
x0 := x0 + optx * vx;
y0 := y0 + vy * optx;
cur := cur + vx * vx * (sx2 - 2 * sx * x0 + n * x0 * x0);
cur := cur + vy * vy * (sy2 - sy * y0 * 2 + n * y0 * y0);
cur := cur + vx * vy * 2 * (sxy - sx * y0 - sy * x0 + n * x0 * y0);
if cur < best then begin
best := cur;
cx := x0;
cy := y0;
end;
end;
end;
ans := 0;
for i := 1 to n do begin
dx := cx - x[i];
dy := cy - y[i];
ans := ans + dx * dx + dy * dy;
end;
writeln(ans : 0 : 17);
end.