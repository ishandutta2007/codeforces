program Project22A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, min, i: Integer;
  a: array[1..100] of Integer;

begin
  min := 101;
  readln(n);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 1 to n do begin
    if a[i] < min then
      min := a[i];
  end;
  for i := 1 to n do begin
    if a[i] = min then
      a[i] := 101;
  end;
  min := 101;
    for i := 1 to n do begin
    if a[i] < min then
      min := a[i];
  end;
  if min = 101 then
    Writeln('NO')
  else
    Writeln(min);
  readln;
  readln;
end.