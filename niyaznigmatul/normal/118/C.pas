
var z, n, k, i, cur, got, d, j, ans : longint;
    c : char;
    cn : array[0 .. 10] of longint;
    s, t, anss : array[0 .. 12345] of longint;
    ok : boolean;
    
begin
    read(n, k);
    read(c);
    while not (c in ['0' .. '9']) do read(c);
    fillchar(cn, sizeof(cn), 0);
    for i := 1 to n do begin
        s[i] := ord(c) - ord('0');
        inc(cn[s[i]]);
        read(c);
    end;
    ans := maxlongint;
    for i := 0 to 9 do begin
        cur := 0;
        got := cn[i];
        for d := 1 to 9 do begin
            if got >= k then break;
            j := i - d;
            if j >= 0 then begin
                if cn[j] + got >= k then begin
                    cur += d * (k - got);
                    break;
                end else begin
                    got += cn[j];
                    cur += d * cn[j];
                end;
            end;
            j := i + d;
            if j < 10 then begin
                if cn[j] + got >= k then begin
                    cur += d * (k - got);
                    break;
                end else begin
                    got += cn[j];
                    cur += d * cn[j];
                end;
            end;
        end;
        got := cn[i];
        for z := 1 to n do t[z] := s[z];
        for d := 1 to 9 do begin
            j := i + d;
            if j < 10 then begin
                for z := 1 to n do begin
                    if (got >= k) then break;
                    if s[z] <> j then continue;
                    t[z] := i;
                    inc(got);
                end;
            end;
            j := i - d;
            if j >= 0 then begin
                for z := n downto 1 do begin
                    if (got >= k) then break;
                    if s[z] <> j then continue;
                    t[z] := i;
                    inc(got);
                end;
            end;
        end;
        if ans > cur then begin
            for z := 1 to n do anss[z] := t[z];
            ans := cur;
        end else if ans = cur then begin 
            ok := false;
            for z := 1 to n do begin
                if t[z] < anss[z] then begin
                    ok := true;
                    break;
                end;
                if t[z] > anss[z] then break;
            end;
            if ok then begin
                for z := 1 to n do anss[z] := t[z];
            end;
        end;
    end;
    writeln(ans);
    for i := 1 to n do write(anss[i]);
    writeln;
end.