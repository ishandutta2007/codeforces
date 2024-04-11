var c : char;
    a, b, ans : longint;
    
begin
    read(c);
    while not (c in ['C', 'P']) do read(c);
    a := 0;
    b := 0;
    ans := 0;
    while c in ['C', 'P'] do begin
        if (c = 'C') then begin
            if b <> 0 then inc(ans);
            if a = 5 then begin
                inc(ans);
                a := 0;
            end;
            b := 0;
            inc(a);
        end else begin
            if (a <> 0) then inc(ans);
            a := 0;
            if b = 5 then begin
                inc(ans);
                b := 0;
            end;
            inc(b);
        end;
        read(c);
    end;
    inc(ans);
    writeln(ans);
end.