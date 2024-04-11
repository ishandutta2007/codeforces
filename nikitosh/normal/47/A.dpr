program Project47A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n: Integer;

begin
  Readln(n);
  for i := 1 to n do begin
    if i * (i + 1) = 2 * n then
    begin
      Writeln('YES');
      Exit;
    end;
  end;
  Writeln('NO');
  readln;
  readln;
end.