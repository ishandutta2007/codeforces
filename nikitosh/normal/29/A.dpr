program Project29A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, j, n: Integer;
  b: Boolean;
  a, d, x: array[1..100] of Integer;

begin
  readln(n);
  b := False;
  for i := 1 to n do begin
    Readln(x[i], d[i]);
    a[i] := x[i] + d[i];
  end;
  for i := 1 to n do begin
    for j := 1 to n do begin
      if (a[i] = x[j]) and (a[j] = x[i]) then
      begin
        b := True;
        Break;
      end;
    end;
  end;
  if b = true then
    Writeln('YES')
  else
    Writeln('NO');
  Readln;
  readln;
end.