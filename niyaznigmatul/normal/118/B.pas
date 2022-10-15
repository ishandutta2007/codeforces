
var n, i, j, k : longint;

begin
    read(n);
    for i := -n to n do begin
        j := i;
        if j < 0 then j := -j;
        for k := 1 to j do write('  ');
        for k := 0 to n - j do begin
            if k > 0 then write(' ');
            write(k);
        end;
        for k := n - j - 1 downto 0 do begin
            write(' ');
            write(k);
        end;
        writeln;
    end;
end.