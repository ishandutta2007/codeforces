program Project25A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, l, x, y, p, q, n, i, a: Integer;

begin
  k := 0;
  l := 0;
  Readln(n);
  for i := 1 to n do begin
    read(a);
    x := k;
    y := l;
    if a mod 2 = 0 then
      inc(k)
    else
      inc(l);
    if (x = 0) and (k = 1) then
      p := i;
    if (y = 0) and (l = 1) then
      q := i;
  end;
  if k = 1 then
    Writeln(p)
  else
    Writeln(q);
  readln;
  readln;
end.