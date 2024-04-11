program Project104A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, k: integer;

begin
  Readln(n);
  if (n <= 10) or (n >= 21) then
    k := 0;
  if (n >= 11) and (n <= 19) then
    k := 4;
  if n = 20 then
    k := 15;
  if n = 21 then
    k := 4;
  Writeln(k);
  readln;
  readln;
end.