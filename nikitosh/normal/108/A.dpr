program Project108A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, i, a, b, c, d: Integer;
  s: string;

function palindrom(k: Integer): Boolean;

begin
  Result := False;
  a := k mod 10;
  k := k div 10;
  b := k mod 10;
  k := k div 10;
  c := k mod 10;
  k := k div 10;
  d := k;
  if (a = d) and (b = c) then
    Result := true;
  if b >= 6 then
    Result := False;
end;

begin
  k := 0;
  Readln(s);
  a := StrToInt(s[1]) * 1000 + StrToInt(s[2]) * 100 + StrToInt(s[4]) * 10 + StrToInt(s[5]);
  for i := a + 1 to 2359 do begin
    if palindrom(i) then
    begin
      k := i;
      break;
    end;
  end;
  if k = 0 then
    Writeln('00:00')
  else
    Writeln(k div 1000, (k div 100) mod 10, ':', (k div 10) mod 10, k mod 10);
  readln;
  readln;
end.