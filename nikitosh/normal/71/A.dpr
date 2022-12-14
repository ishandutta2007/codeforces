program Project71A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n: integer;
  s: string;

begin
  Readln(n);
  for i := 1 to n do begin
    Readln(s);
    if Length(s) <= 10 then
      Writeln(s);
    if Length(s) > 10 then
    begin
      writeln(s[1], Length(s) - 2, s[Length(s)]);
    end;
  end;
  readln;
  readln;
end.