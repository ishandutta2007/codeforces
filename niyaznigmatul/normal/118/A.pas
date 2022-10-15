
var c : char;

begin
    read(c);
    while c in ['a' .. 'z', 'A' .. 'Z'] do begin
        if c in ['A' .. 'Z'] then c := chr(ord(c) - ord('A') + ord('a'));
        if c in ['a', 'o', 'e', 'i', 'u', 'y'] then begin
        
        end else begin
            write('.');
            write(c);
        end;
        read(c);
    end;
end.