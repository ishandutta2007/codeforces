program Project46A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, k, n: Integer;

begin
  k := 1;
  Readln(n);
  for i := 1 to n - 1 do begin
    k := (k + i) mod n;
    if k = 0 then
      k := n;
    write(k, ' ');
  end;
  readln;
  readln;
end.