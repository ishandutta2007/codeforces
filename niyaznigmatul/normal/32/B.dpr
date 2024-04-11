var s : string;
i : integer;

begin
read(s);
i := 1;
while (i <= length(s)) do
    begin
        if (s[i] = '.') then
            begin
                write(0);
                inc(i);
            end else
            begin
                if (s[i + 1] = '-') then
                    write(2) else write(1);
                inc(i, 2);
            end;
    end;
end.