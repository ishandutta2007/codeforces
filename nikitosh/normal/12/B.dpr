program Project12B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  N, i, m, j: Integer;
  a: array [1..9] of integer;
  s, t: string;

procedure swap(var k, l: Integer);

begin
  m := k;
  k := l;
  l := m;
end;

begin
  Readln(s);
  Readln(t);
  for i := 1 to Length(s) do begin
    a[i] := StrToInt(s[i]);
  end;
  N := Length(s);
  for i := 1 to N do begin
    for j := 1 to N - 1 do begin
      if a[j] > a[j + 1] then
        Swap(a[j], a[j + 1]);
    end;
  end;
  for i := 1 to N do begin
    if a[i] <> 0 then
    begin
      Swap(a[i], a[1]);
      Break;
    end;
  end;
  if length(s) <> Length(t) then
  begin
    writeln('WRONG_ANSWER');
    exit;
  end;
  for i := 1 to N do begin
    if a[i] <> StrToInt(t[i]) then
    begin
      writeln('WRONG_ANSWER');
      Exit;
    end;
  end;
  writeln('OK');
  readln;
  readln;
end.