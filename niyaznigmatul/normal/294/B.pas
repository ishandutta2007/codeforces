

var tmp, n, one, two, i, j, ans, i1, i2, wid, k : longint;
    t, w : array[0 .. 123] of longint;
begin
    read(n);
    one := 0;
    two := 0;
    for i := 1 to n do begin
        read(t[i], w[i]);
        if (t[i] = 1) then inc(one) else inc(two);
    end;
    for i := 1 to n do
        for j := i + 1 to n do begin
            if (w[i] > w[j]) then begin
                tmp := t[i]; t[i] := t[j]; t[j] := tmp;
                tmp := w[i]; w[i] := w[j]; w[j] := tmp;
            end;
        end;
    ans := maxlongint;
    for i := 0 to one do begin
        for j := 0 to two do begin
            i1 := one - i;
            i2 := two - j;
            wid := 0;
            for k := 1 to n do begin
                if (t[k] = 1) and (i1 > 0) then begin
                    dec(i1);
                    wid += w[k];
                end;
                if (t[k] = 2) and (i2 > 0) then begin
                    dec(i2);
                    wid += w[k];
                end;
            end;
            assert(i1 = 0);
            assert(i2 = 0);
            if (wid > i + 2 * j) then continue;
            if (ans > i + 2 * j) then ans := i + 2 * j;
        end;        
    end;
    writeln(ans);
end.