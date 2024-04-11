program Project84A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, n: Int64;
  s: string;

function schastie(n: int64): Boolean;

var
  i: Integer;

begin
  k := 0;
  Result := False;
  s := IntToStr(n);
  for i := 1 to length(s) do begin
    if (s[i] = '4') or (s[i] = '7') then
      inc(k);
  end;
  if k = length(s) then
    Result := True;
end;

function schastie2(n: int64): integer;

var
  i: Integer;

begin
  result := 0;
  s := IntToStr(n);
  for i := 1 to length(s) do begin
    if (s[i] = '4') or (s[i] = '7') then
      inc(result);
  end;
end;


begin
  Readln(n);
  if schastie(schastie2(n)) then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.