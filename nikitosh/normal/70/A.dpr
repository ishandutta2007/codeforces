program Project70A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, k: integer;

begin
  k := 1;
  Readln(n);
  for i := 1 to n - 1 do begin
    k := k * 3;
    if k > 1000003 then
      k := k mod 1000003;
  end;
  Writeln(k);
  readln;
  readln;
end.