program Project102B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s: string;
  x: int64;

function summ(s: string): Integer;

var
  i: Integer;

begin
  result := 0;
  for i := 1 to Length(s) do begin
    result := result + StrToInt(s[i]);
  end;
end;

begin
  x := 0;
  Readln(s);
  while summ(s) > 9 do begin
    s := IntToStr(summ(s));
    Inc(x);
  end;
  if Length(s) > 1 then
    Writeln(x + 1)
  else
    Writeln(x);
  Readln;
  readln;
end.