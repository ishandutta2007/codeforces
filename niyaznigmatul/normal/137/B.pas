
var x, n, i, ans : longint;
    a : array[0 .. 5555] of longint;
    
begin
    read(n);
    fillchar(a, sizeof(a), 0);
    for i := 1 to n do begin
        read(x);
        inc(a[x]);
    end;
    ans := 0;
    for i := 1 to n do if a[i] = 0 then inc(ans);
    writeln(ans);
end.