
const MAXN = 1777777;
        SHIFT = 444444;

var f : array[0 .. MAXN] of longint;

function get(x : longint) : longint;
var res : longint;
    begin
        res := maxlongint;
        while x >= 0 do begin
            if res > f[x] then res := f[x];
            x := (x and (x + 1)) - 1;
        end;
        get := res;
    end;
    
    
procedure md(x, y : longint);
    begin
        while x < MAXN do begin
            if f[x] > y then f[x] := y;
            x := x or (x + 1);
        end;
    end;

var c : char;
    cur, b, i, cn, ans, d : longint;
    
begin
    read(c);
    while not (c in ['a' .. 'z', 'A' .. 'Z']) do read(c);
    for i := 0 to MAXN do f[i] := maxlongint;
    b := 0;
    i := 0;
    cn := 0;
    ans := -maxlongint;
    md(SHIFT, 0);
    while c in ['a' .. 'z', 'A' .. 'Z'] do begin
        inc(i);
        if c in ['A' .. 'Z'] then c := chr(ord(c) - ord('A') + ord('a'));
        if c in ['a', 'u', 'i', 'o', 'e'] then d := -1 else d := 2;
        b += d;
        cur := get(SHIFT + b);
        if cur <> maxlongint then begin
            cur := i - cur;
            if cur > ans then begin
                ans := cur;
                cn := 1;
            end else if cur = ans then inc(cn);
        end;
        md(SHIFT + b, i);
        read(c);
    end;
    if ans = -maxlongint then writeln('No solution') else
    writeln(ans, ' ', cn);
end.