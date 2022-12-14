program Project32A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, d, i, j, x: Integer;
  a: array[1..1000] of integer;

begin
  x := 0;
  Readln(n, d);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 1 to n do begin
    for j := 1 to n do begin
      if (i <> j) and (Abs(a[i] - a[j]) <= d) then
        inc(x);
    end;
  end;
  Writeln(x);
  readln;
  readln;
end.