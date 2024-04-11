program Project43A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, k, l, i: Integer;
  s, r, q: string;

begin
  k := 0;
  l := 0;
  Readln(n);
  Readln(s);
  r := s;
  k := 1;
  for i := 1 to n - 1 do begin
    readln(s);
    if s = r then
      Inc(k)
    else
    begin
      inc(l);
      q := s;
    end;
  end;
  if k > l then
    Writeln(r)
  else
    writeln(q);
  Readln;
  readln;
end.