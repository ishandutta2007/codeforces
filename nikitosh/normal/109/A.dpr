program Project109A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  k, n, i, m, l: Integer;

begin
  Readln(n);
  m := -1;
  l := 0;
  k := n div 4;
  for i := 0 to k do begin
    if (n - 4 * i) mod 7 = 0 then
    begin
      m := i;
      l := (n - 4 * i) div 7;
      Break;
    end;
  end;
  if m = -1 then
  begin
    write('-1');
    Exit;
  end;
  for i := 1 to m do begin
    write('4');
  end;
  for i := 1 to l do begin
    write('7');
  end;
  readln;
  readln;
end.