

var n, m, x, y, i : longint;
    a : array[0 .. 123] of longint;
begin
    read(n);
    for i := 1 to n do begin
        read(a[i]);
    end;
    read(m);
    for i := 1 to m do begin
        read(x, y);
        if (x > 1) then a[x - 1] += y - 1;
        if (x + 1 <= n) then a[x + 1] += a[x] - y;
        a[x] := 0;
    end;
    for i := 1 to n do writeln(a[i]);
end.