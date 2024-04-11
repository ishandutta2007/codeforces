program Project26A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, x, i, j, k: Integer;

function prostoe(n: Integer): Boolean;

var
  i: Integer;

begin
  Result := True;
  for i := 2 to n - 1 do begin
    if n mod i = 0 then Result := False;
  end;
end;

begin
  k := 0;
  Readln(n);
  for i := 2 to n do begin
    x := 0;
    for j := 2 to i do begin
      if (i mod j = 0) and (prostoe(j)) then
      Inc(x);
    end;
    if x = 2 then
      Inc(k);
  end;
  Writeln(k);
  readln;
  readln;
end.