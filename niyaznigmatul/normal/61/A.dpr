var
    s, t: string;
    i: integer;
begin
    readln(s);
    readln(t);
    for i := 1 to length(s) do 
        if (s[i] = t[i]) then
            write(0)
        else
            write(1);
end.