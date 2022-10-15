
const MN = 777777;
var rem, n, m : longint;
    dws, dp : array[0 .. MN] of int64;
    pv, id, ss, ff, w, he, ne, dwc : array[0 .. MN] of longint;
    was : array[0 .. MN] of boolean;
    
procedure dfs(v, cid : longint);
var e : longint;
    begin
        was[v] := true;
        id[v] := cid;
        e := he[v];
        dws[v] := 0;
        dwc[v] := 1;
        while e >= 0 do begin
            if (e = rem) or (e = rem + m) then begin
                e := ne[e];
                continue;
            end;
            if not was[ff[e]] then begin
                pv[ff[e]] := v;
                dfs(ff[e], cid);
                dws[v] += dws[ff[e]] + int64(w[e]) * dwc[ff[e]];
                dwc[v] += dwc[ff[e]];
            end;
            e := ne[e];
        end;
//        writeln(v, ' ', dws[v], ' ', dwc[v]);
    end;
    
procedure dfs2(v: longint; cw : longint; sw : int64);
var e, ncw : longint; nsw : int64;
    begin
        e := he[v];
        dp[v] := dws[v] + sw;
//        writeln(v, ' ', cw, ' ', sw, ' ', dp[v]);
        while e >= 0 do begin
            if (e = rem) or (e = rem + m) then begin
                e := ne[e];
                continue;
            end;
            if (ff[e] <> pv[v]) then begin 
                ncw := cw + dwc[v] - dwc[ff[e]];
                nsw := dws[v] - dws[ff[e]] - int64(w[e]) * dwc[ff[e]] + sw + int64(w[e]) * ncw;
                dfs2(ff[e], ncw, nsw);
            end;
            e := ne[e];
        end;
    end;

var sd, fd, cn, tmp, dd, m1, m2, cnt1, cnt2, i : longint;
    ini, cur, ans : int64;

begin
    read(n);
    m := n - 1;
    for i := 1 to m do begin
        read(ss[i], ff[i], w[i]);
        ss[i + m] := ff[i];
        ff[i + m] := ss[i];
        w[i + m] := w[i];
    end;    
    for i := 1 to n do begin
        he[i] := -1;
        was[i] := false;
    end;
    for i := 1 to m+m do begin
        ne[i] := he[ss[i]];
        he[ss[i]] := i;
    end;
    rem := m + m + 1;
    pv[1] := 1;
    dfs(1, 0);
    dfs2(1, 0, 0);
    ini := 0;
    for i := 1 to n do ini += dp[i];
    ini := ini shr 1;
    ans := int64(maxlongint) * maxlongint;
    for dd := 1 to m do begin
//        writeln;
//        writeln('dd = ', dd);
        rem := dd;
        cn := 0;
        for i := 1 to n do was[i] := false;
        for i := 1 to n do begin
            if was[i] then continue;
            pv[i] := i;
            dfs(i, cn);
//            writeln;
            dfs2(i, 0, 0);
            inc(cn);
//            writeln;
//            writeln;
        end;
        m1 := -1;
        m2 := -1;
        cnt1 := 0;
        for i := 1 to n do begin
            if id[i] = 0 then begin
                inc(cnt1);
                if (m1 < 0) or (dp[m1] > dp[i]) then m1 := i;
            end else begin
                if (m2 < 0) or (dp[m2] > dp[i]) then m2 := i;
            end;
        end;
        cnt2 := n - cnt1;
        sd := ss[dd];
        fd := ff[dd];
        if (id[sd] = 1) then begin
            tmp := sd; sd := fd;
            fd := tmp;
        end;
        cur := ini + cnt2 * (dp[m1] - dp[sd]) + cnt1 * (dp[m2] - dp[fd]);
        if (ans > cur) then ans := cur;
    end;
    writeln(ans);
end.