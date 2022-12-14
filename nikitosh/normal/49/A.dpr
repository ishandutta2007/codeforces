program Project49A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, k: Integer;
  s: string;

begin
  Readln(s);
  for i := Length(s) downto 1 do begin
    if (s[i] <> '?') and (s[i] <> ' ') then
    begin
      k := i;
      Break;
    end;
  end;
  if (s[k] = 'a') or (s[k] = 'e') or (s[k] = 'i') or (s[k] = 'o') or (s[k] = 'u') or (s[k] = 'y') or (s[k] = 'E') or (s[k] = 'A') or (s[k] = 'I') or (s[k] = 'O') or (s[k] = 'U') or (s[k] = 'Y') then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.