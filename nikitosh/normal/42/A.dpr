program Project42A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n, V, x: Integer;
  a, b: array[1..20] of Integer;
  k, min: Extended;
  c: array[1..20] of extended;

begin
  Readln(n, V);
  min := 1000;
  x := 0;
  for i := 1 to n do begin
    read(a[i]);
    x := x + a[i];
  end;
  for i := 1 to n do begin
    read(b[i]);
    c[i] := b[i] / a[i];
  end;
  for i := 1 to n do begin
    if c[i] < min then
      min := c[i];
  end;
  k := min * x;
  if k > V then
    k := V;
  Writeln(k: 0: 12);
  Readln;
  readln;
end.