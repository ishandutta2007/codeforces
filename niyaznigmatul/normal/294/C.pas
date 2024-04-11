
const md = 1000000007;
var i, n, m, j, left, x, z, tmp : longint;
    ans : int64;
    c : array[0 .. 1234, 0 .. 1234] of longint;
    a : array[0 .. 1234] of longint;
    
begin
    for i := 0 to 1222 do begin
        c[i][0] := 1;
        for j := 1 to i do begin
            c[i][j] := c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= md) then c[i][j] -= md;
        end;
    end; 
    read(n, m);
    for i := 1 to m do begin
        read(a[i]);
    end;
    for i := 1 to m do
        for j := i + 1 to m do 
            if (a[i] > a[j]) then begin
                tmp := a[i]; a[i] := a[j]; a[j] := tmp;
            end;
    ans := 1;
    for i := 2 to m do begin
        if a[i] - 1 > a[i - 1] then begin
            for j := a[i - 1] to a[i] - 3 do begin
                ans += ans;
                if ans >= md then ans -= md;
            end;
        end;
    end;
    a[m + 1] := n + 1;
    left := n - m;
    inc(m);
    x := 0;
    for i := 1 to m do begin
        z := a[i] - x - 1;
        if (z > 0) then begin
            ans := ans * c[left][z] mod md;
            left -= z;
        end;
        x := a[i];
    end;
    writeln(ans);
end.