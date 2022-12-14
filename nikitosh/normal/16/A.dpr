program Project16A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, j, n, m: Integer;
  b: Boolean;
  a: array[1..100, 1..100] of Integer;
  s: string;

begin
  b := True;
  Readln(n, m);
  for i := 1 to n do begin
    Readln(s);
    for j := 1 to m do begin
      a[i][j] := StrToInt(s[j]);
    end;
  end;
  for i := 1 to n do begin
    for j := 2 to m do begin
      if a[i][j] <> a[i][j - 1] then
        b := False;
    end;
  end;
  for i := 2 to n do begin
    if a[i][1] = a[i - 1][1] then
      b := False;
  end;
  if b = true then
    writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.