program Project35A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, l, a, b, i: Integer;

begin
  Reset(input, 'input.txt');
  Rewrite(Output, 'output.txt');
  readln(k);
  l := k;
  for i := 1 to 3 do begin
    Readln(a, b);
    if k = a then
      l := b;
    if k = b then
      l := a;
    k := l;
  end;
  Writeln(k);
  Readln;
  readln;
end.