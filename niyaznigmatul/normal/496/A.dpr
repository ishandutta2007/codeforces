
var
  a : array[0 .. 123456] of longint;
  n, ans, i, j, cur, last : longint;

begin
  read(n);
  for i := 1 to n do read(a[i]);
  ans := maxlongint;
  for i := 2 to n - 1 do begin
    last := a[1];
    cur := 0;
    for j := 2 to n do begin
      if i = j then continue;
      if cur < a[j] - last then cur := a[j] - last;
      last := a[j];
    end;
    if ans > cur then ans := cur;
  end;
  writeln(ans);
end.