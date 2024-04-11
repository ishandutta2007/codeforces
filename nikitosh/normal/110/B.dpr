program Project84B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, n, i: Integer;

begin
  Readln(n);
  k := n div 4;
  for i := 1 to k do begin
    write('abcd');
  end;
  if n mod 4 = 1 then
    write('a');
  if n mod 4 = 2 then
    write('ab');
  if n mod 4 = 3 then
    write('abc');
  readln;
  readln;
end.