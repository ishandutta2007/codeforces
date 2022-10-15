
const dx : array[0 .. 5] of longint = (1, -1, -2, -1, 1, 2);
      dy : array[0 .. 5] of longint = (2, 2, 0, -2, -2, 0);

var
  l, r, mid, cur, d, cx, cy, n : int64;
  dir : longint;

begin
  read(n);
  d := 0;
  dir := 0;
  cx := 0;
  cy := 0;
  l := 0;
  r := 1000000000;
  while l < r - 1 do begin
    mid := (l + r) shr 1;
    if (mid * (mid - 1) shr 1) * 6 + mid * 5 < n then l := mid else r := mid;
  end;
  n := n - ((l * (l - 1) shr 1) * 6 + l * 5);
  cx := l;
  cy := -2 * l;
  d := l;
  while n > 0 do begin
    cur := d;
    if (dir = 0) then begin
      inc(cur);
    end else if dir = 1 then begin
      inc(d);
    end;
    if cur >= n then begin
      cur := n;
    end;
    cx := cx + dx[dir] * cur;
    cy := cy + dy[dir] * cur;
    n := n - cur;
    dir := (dir + 1) mod 6;
  end;
  writeln(cx, ' ', cy);
end.