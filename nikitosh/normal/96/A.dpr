program Project96A;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i: integer;
  s: string;

begin
  Readln(s);
  if length(s) < 7 then
  begin
    Writeln('NO');
    Exit;
  end;
  for i := 1 to Length(s) - 6 do begin
    if (s[i] = s[i + 1]) and (s[i] = s[i + 2]) and (s[i] = s[i + 3]) and (s[i] = s[i + 4]) and (s[i] = s[i + 5]) and (s[i] = s[i + 6]) then
      begin
        Writeln('YES');
        Exit;
      end;
  end;
  Writeln('NO');
  readln;
  readln;
end.