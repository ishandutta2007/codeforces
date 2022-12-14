program ProjectA;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  a, b, k, i: Integer;
  s, t: string;

begin
  Read(a, b);
  s := IntToStr(b);
  t := '';
  for i := 1 to Length(s) do begin
    t := t + s[Length(s) - i + 1];
  end;
  k := StrToInt(t);
  Writeln(a + k);
  readln;
  readln;
end.