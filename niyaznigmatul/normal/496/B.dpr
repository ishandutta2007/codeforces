
var
  a, b, ans : array[0 .. 123456] of longint;
  n, i, j, add : longint;
  ok : boolean;
  ch : char;

begin
  readln(n);
  for i := 1 to n do begin
    read(ch);
    a[i] := ord(ch) - ord('0');
    ans[i] := a[i];
  end;
  for i := 1 to n do begin
    add := 10 - a[i];
    for j := 1 to n do begin
      b[j] := (add + a[(i + j - 2) mod n + 1]) mod 10;
    end;
    ok := false;
    for j := 1 to n do begin
      if b[j] < ans[j] then begin ok := true; break; end;
      if b[j] > ans[j] then begin ok := false; break; end;
    end;
    if ok then for j := 1 to n do ans[j] := b[j];
  end;
  for i := 1 to n do write(ans[i]);
  writeln;
end.