
var n, m, k, i, j, x : longint;
  ok : boolean;
  a : array[0 .. 1234567] of boolean;

begin
  read(n, m);
  for i := 1 to m do a[i] := false;
  for i := 1 to n do begin
    read(k);
    for j := 1 to k do begin
      read(x);
      a[x] := true;
    end;
  end;
  ok := true;
  for i := 1 to m do begin
    if not a[i] then ok := false;
  end;
  if ok then writeln('YES') else writeln('NO');
end.