program Project43C;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, a, k, l, m, i: Integer;

begin
  k := 0;
  l := 0;
  m := 0;
  readln(n);
  for i := 1 to n do begin
    read(a);
    if a mod 3 = 0 then
      inc(k);
    if a mod 3 = 1 then
      inc(l);
    if a mod 3 = 2 then
      inc(m);
  end;
  Writeln(min(l, m) + k div 2);
  Readln;
  readln;
end.