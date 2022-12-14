program Project69A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, x: integer;
  b: Boolean;
  a: array[1..100, 1..3] of integer;

begin
  b := True;
  Readln(n);
  for i := 1 to n do begin
    for j := 1 to 3 do begin
      read(a[i][j]);
    end;
  end;
  for i := 1 to 3 do begin
    x := 0;
    for j := 1 to n do begin
      x := x + a[j][i];
    end;
    if x <> 0 then b := False;
  end;
  if b = true then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.