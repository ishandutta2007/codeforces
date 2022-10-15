{$M 16777216}

var ne, ss, ff : array[0 .. 777777] of longint;
    he, up, de, pv : array[0 .. 111111] of longint;
    aor : array[0 .. 777777] of boolean;
    n, m : longint;
    bad : boolean;


procedure dfs(v : longint);
var e : longint;
    begin
        up[v] := de[v];
        e := he[v];
        while e >= 0 do begin
            if ff[e] = pv[v] then begin e := ne[e]; continue; end;
            if de[ff[e]] >= 0 then begin
                if de[ff[e]] < de[v] then aor[e] := true;
                if up[v] > de[ff[e]] then up[v] := de[ff[e]];
            end else begin
                aor[e] := true;
                pv[ff[e]] := v;
                de[ff[e]] := de[v] + 1;
                dfs(ff[e]);
                if up[ff[e]] > de[v] then bad := true;
                if up[v] > up[ff[e]] then up[v] := up[ff[e]];
            end;
            e := ne[e];
        end;
    end;
    
var i : longint;

begin
    read(n, m);
    for i := 1 to m do begin
        read(ss[i], ff[i]);
        ss[i + m] := ff[i];
        ff[i + m] := ss[i];
    end;
    for i := 1 to n do begin
        he[i] := -1;
        de[i] := -1;
    end;
    for i := 1 to m + m do begin
        ne[i] := he[ss[i]];
        he[ss[i]] := i;
    end;
    fillchar(aor, sizeof(aor), false);
    bad := false;
    de[1] := 0;
    pv[1] := 1;
    dfs(1);
    if bad then begin
        writeln(0);
        halt(0);
    end;
    for i := 1 to m + m do begin
        if aor[i] then writeln(ss[i], ' ', ff[i]);
    end;
end.