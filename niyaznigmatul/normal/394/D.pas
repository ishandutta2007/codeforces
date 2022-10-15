var a : array[0 .. 12345] of longint;
ansf, ansk : longint;

n, i, j, tmp, k, mn, mx, ans : longint;
begin
read(n);
for i := 1 to n do read(a[i]);
for i := 1 to n do
for j := i + 1 to n do if a[i ]> a[j] then begin tmp := a[i]; a[i] := a[j]; a[j] := tmp; end;
ans := maxlongint;
for k := 0 to 22222 do begin
mn := maxlongint;
mx := -maxlongint;
for i := 1 to n do begin
tmp := a[i] - k * i;
if tmp < mn then mn := tmp;
if mx < tmp then mx := tmp;
end;
tmp := mx - mn + 1;
tmp := tmp div 2;
if tmp < ans then begin
ans := tmp;
ansf := k + (mn + mx) div 2;

ansk := k;
end;
end;
writeln(ans);
writeln(ansf, ' ', ansk);
end.