program Project34B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, min, k, n, x, m, j: Integer;
  a: array[1..100] of integer;

begin
  x := 0;
  readln(n, m);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 1 to m do begin
    min := 1000;
    for j := 1 to n do begin
      if a[j] < min then
      begin
        min := a[j];
        k := j;
      end;
    end;
    if a[k] < 0 then
      x := x + Abs(a[k])
    else
      Break;
    a[k] := 1000;
  end;
  Writeln(x);
  readln;
  readln;
end.