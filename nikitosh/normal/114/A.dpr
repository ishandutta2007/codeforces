program ProjectA;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  l: Int64;
  k, x, i: Integer;

begin
  x := 0;
  Readln(k, l);
  for i := 1 to 32 do begin
    if l = 1 then
      Break;
    if l mod k <> 0 then
    begin
      x := 0;
      Break;
    end;
    l := l div k;
    inc(x);
  end;
  if x <> 0 then
  begin
    Writeln('YES');
    Writeln(x - 1);
  end
  else
    Writeln('NO');
  readln;
  readln;
end.