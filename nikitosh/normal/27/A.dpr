program Project27A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, k: Integer;
  b: Boolean;
  a: array[1..3000] of integer;

begin
  Readln(n);
  for i := 1 to n do begin
    read(a[i]);
  end;
  for i := 1 to 3001 do begin
    b := True;
    for j := 1 to n do begin
      if a[j] = i then b := False;
    end;
    if b = True then
    begin
      k := i;
      Break;
    end;
  end;
  Writeln(k);
  readln;
  readln;
end.