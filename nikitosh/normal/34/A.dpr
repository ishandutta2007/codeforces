program Project34A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, min, k, n: Integer;
  a: array[1..100] of integer;

begin
  min := 1000;
  Readln(n);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 2 to n do begin
    if Abs(a[i] - a[i - 1]) < min then
    begin
      min := Abs(a[i] - a[i - 1]);
      k := i;
    end;
  end;
  if Abs(a[1] - a[n]) < min then
    write(n, ' ', 1)
  else
    write(k - 1, ' ', k);
  readln;
  readln;
end.