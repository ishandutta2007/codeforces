program Project38A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, x, a, b: Integer;
  d: array[1..100] of integer;

begin
  x := 0;
  Readln(n);
  for i := 1 to n - 1 do begin
    read(d[i]);
  end;
  Readln(a, b);
  for i := a to b - 1 do begin
    x := x + d[i];
  end;
  Writeln(x);
  readln;
  readln;
end.