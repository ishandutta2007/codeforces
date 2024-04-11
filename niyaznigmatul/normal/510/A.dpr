
var n, m, i, j : longint;

begin
read(n, m);
for i := 1 to n do if (odd(i)) then begin
for j := 1 to m do write('#');
writeln;
end else begin
if not odd(i div 2) then write('#');
for j := 2 to m do write('.');
if odd(i div 2) then write('#');
writeln;
end;
end.