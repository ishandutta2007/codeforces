program ProjectAA;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n, max, x, a, b: Integer;

begin
  max := 0;
  x := 0;
  Readln(n);
  for i := 1 to n do begin
    read(a, b);
    x := x + b - a;
    if x > max then
      max := x;
  end;
  Writeln(max);
  readln;
  readln;
end.