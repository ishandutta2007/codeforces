var s : string;
a, b, c, i : longint;
begin
readln(s);
a := pos('+', s) - 1;
b := pos('=', s) - a - 2;
c := length(s) - a - b - 2;
if a + b + 1 = c - 1 then begin dec(c); inc(a); end;
if a + b - 1= c + 1 then begin 
if a = 1 then dec(b) else dec(a); inc(c);
end;
if (a + b = c) and (a >= 1) and (b >= 1) then begin
for i := 1 to a do write('|'); write('+');
for i := 1 to b do write('|');
write('=');
for i := 1 to c do write('|');
writeln;
end else begin
writeln('Impossible');
end;
end.