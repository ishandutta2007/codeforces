program Project37A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, x, max, k: Integer;
  a: array[1..1000] of integer;

begin
  x := 0;
  Readln(n);
  for i := 1 to n do begin
    a[i] := 0;
  end;
  for i := 1 to n do begin
    read(k);
    inc(a[k]);
  end;
  max := 0;
  for i := 1 to 1000 do begin
    if a[i] <> 0 then
      inc(x);
    if a[i] > max then
      max := a[i];
  end;
  Writeln(max, ' ', x);
  readln;
  readln;
end.