program Project33A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, x, n, m, k, y, z: integer;
  a: array[1..1000] of Integer;

begin
  x := 0;
  Readln(n, m, k);
  for i := 1 to m do begin
    a[i] := 1000000;
  end;
  for i := 1 to n do begin
    read(y, z);
    if z < a[y] then
      a[y] := z;
  end;
  for i := 1 to m do begin
    x := x + a[i];
    if x > k then
    begin
      x := k;
      Break;
    end;
  end;
  Writeln(x);
  readln;
  readln;
end.