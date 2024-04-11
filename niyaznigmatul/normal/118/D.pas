const md = 100000000;

var dp : array[0 .. 111, 0 .. 111, 0 .. 11, 0 .. 11] of longint;
    ans, n1, n2, k1, k2, i, j, z1, z2 : longint;
    
begin
    read(n1, n2, k1, k2);
    fillchar(dp, sizeof(dp), 0);
    dp[0][0][0][0] := 1;
    for i := 0 to n1 do begin
        for j := 0 to n2 do begin
            for z1 := 0 to k1 do begin
                for z2 := 0 to k2 do begin
                    if (z1 > 0) and (z2 > 0) then continue;
                    if (z1 < k1) then begin
                        dp[i + 1][j][z1 + 1][0] += dp[i][j][z1][z2];
                        if dp[i + 1][j][z1 + 1][0] >= md then dp[i + 1][j][z1 + 1][0] -= md;
                    end;
                    if (z2 < k2) then begin
                        dp[i][j + 1][0][z2 + 1] += dp[i][j][z1][z2];
                        if dp[i][j + 1][0][z2 + 1] >= md then dp[i][j + 1][0][z2 + 1] -= md;
                    end;
                end;
            end;
        end;
    end;
    ans := 0;
    for i := 0 to k1 do for j := 0 to k2 do begin
        ans += dp[n1][n2][i][j];
        if ans >= md then ans -= md;
    end;
    writeln(ans);
end.