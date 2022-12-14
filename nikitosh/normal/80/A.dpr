program Project80A;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i, j, n, m, k: integer;
  b: Boolean;

begin
  Readln(n, m);
  for i := n + 1 to 53 do begin
    b := True;
    for j := 2 to i - 1 do begin
      if i mod j = 0 then
        b := False;
    end;
    if b = True then
    begin
      k := i;
      break;
    end;
  end;
  if k = m then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.