
var s : array[0 .. 555] of char;
    dp : array[0 .. 555, 0 .. 555] of longint;
    ch : array[0 .. 555, 0 .. 555] of longint;
    val, mk, f, best, n, i, le, j, z, k : longint;
    found : boolean;
    c : char;

begin
    read(c);
    while not (c in ['a' .. 'z', 'A' .. 'Z']) do read(c);
    n := 0;
    while c in ['a' .. 'z', 'A' .. 'Z'] do begin
        inc(n);
        s[n] := c;
        read(c);
    end;    
    read(mk);
    for i := 1 to n do ch[i][i] := 0;
    for i := 1 to n - 1 do if s[i] = s[i + 1] then ch[i][i + 1] := 0 else ch[i][i + 1] := 1;
    for le := 2 to n - 1 do begin
        for i := 1 to n - le do begin
            j := i + le;
            if s[i] = s[j] then ch[i][j] := ch[i + 1][j - 1] else
            ch[i][j] := ch[i + 1][j - 1] + 1;
        end;
    end;
    for i := 0 to mk do 
        for j := 1 to n + 1 do 
            dp[i][j] := maxlongint;
    dp[0][n + 1] := 0;
    for i := n downto 1 do begin
        for k := 1 to mk do begin
            dp[k][i] := maxlongint;
            for j := i to n do begin
                val := dp[k - 1][j + 1];
                if val = maxlongint then continue;
                val += ch[i][j];
                if dp[k][i] > val then dp[k][i] := val;
            end;
        end;
    end;
    best := maxlongint;
    for i := 1 to mk do if dp[i][1] < best then begin
        best := dp[i][1];
        f := i;
    end;
    i := 1;
    writeln(best);
    while i <= n do begin
        found := false;
        for j := i to n do begin
            val := dp[f - 1][j + 1];
            if val = maxlongint then continue;
            val += ch[i][j];
            if dp[f][i] = val then begin
                found := true;
                for k := i to j do begin
                    z := i + j - k;
                    if z > k then z := k;
                    write(s[z]);
                end;
                i := j + 1;
                dec(f);
                break;
            end;
        end;
        if f > 0 then write('+');
        assert(found);
    end;
    writeln;
end.