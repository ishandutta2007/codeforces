program Project12A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, j: Integer;
  b: Boolean;
  s, t, r: string;
  a: array[1..3, 1..3] of Char;

begin
  Readln(s);
  Readln(t);
  readln(r);
  b := True;
  for i := 1 to 3 do begin
    a[1][i] := s[i];
    a[2][i] := t[i];
    a[3][i] := r[i];
  end;
  for i := 1 to 3 do begin
    for j := 1 to 3 do begin
      if (a[i][j] = 'X') and (a[4 - i][4 - j] <> 'X') then
        b := False;
    end;
  end;
  if b = true then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.