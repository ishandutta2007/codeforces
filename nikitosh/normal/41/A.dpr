program Project41A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s, t: string;
  i: Integer;
  b: Boolean;

begin
  b := true;
  readln(s);
  Readln(t);
  if Length(s) <> Length(t) then b := False;
  for i := 1 to Length(s) do begin
    if s[i] <> t[Length(s) - i + 1] then
      b := False;
  end;
  if b = true then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.