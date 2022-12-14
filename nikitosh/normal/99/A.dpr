program Project99A;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  k, l, m, i: integer;
  s: string;

begin
  Readln(s);
  for i := 1 to Length(s) do begin
    if s[i] = '.' then
    begin
      k := StrToInt(s[i + 1]);
      l := StrToInt(s[i - 1]);
      m := i;
      Break;
    end;
  end;
  if l = 9 then
  begin
    Writeln('GOTO Vasilisa.');
    Exit;
  end;
  if k < 5 then
  begin
    for i := 1 to m - 1 do begin
      write(s[i]);
    end;
  end
  else
  begin
    for i := 1 to m - 2 do begin
      write(s[i]);
    end;
    write(l + 1);
  end;
  readln;
  readln;
end.