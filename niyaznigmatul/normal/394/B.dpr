var a : array[0 .. 1234567] of longint;
b, k, x, i, md, p : longint;
begin
read(p, x);
if p = 1 then begin
if x = 1 then writeln(1) else writeln('Impossible');
halt(0);
end;
for b := 1 to 9 do begin
a[1] := 10 - x;
for i := 2 to p - 1 do a[i] := 9;
for i := 1 to p - 1 do a[i] := a[i] * b;
a[p] := 0;
for i := 1 to p - 1 do begin
a[i + 1] := a[i + 1]+ a[i] div 10;
a[i] := a[i] mod 10;
end;
k := 10 * x - 1;
md := 0;
for i := p downto 1 do begin
md := md * 10 + a[i];
a[i] := md div k;
md := md mod k;
end;
if md <> 0 then continue;
if a[p] <> 0 then continue;
if a[p - 1] = 0 then continue;
for i := p - 1 downto 1 do write(a[i]);
writeln(b);
halt(0);
end;
writeln('Impossible');
end.