program ProjectBB;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  x, n, m, i, j: Integer;
  s: string;
  a: array[0..11, 0..11] of Char;

begin
  x := 0;
  Readln(n, m);
  for i := 0 to n + 1 do begin
    for j := 0 to m + 1 do begin
      a[i][j] := '.'
    end;
  end;
  for i := 1 to n do begin
    Readln(s);
    for j := 1 to Length(s) do begin
      a[i][j] := s[j];
    end;
  end;
  for i := 1 to n do begin
    for j := 1 to m do begin
      if (a[i][j] = 'W') and ((a[i][j + 1] = 'P') or (a[i][j - 1] = 'P') or (a[i + 1][j] = 'P') or (a[i - 1][j] = 'P')) then
        Inc(x);
    end;
  end;
  Writeln(x);
  readln;
  readln;
end.