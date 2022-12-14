program Project78A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, x, y, z: integer;
  s, t, r: string;

begin
  x := 0;
  y := 0;
  z := 0;
  Readln(s);
  Readln(t);
  Readln(r);
  for i := 1 to Length(s) do begin
    if (s[i] = 'a') or (s[i] = 'o') or (s[i] = 'e') or (s[i] = 'i') or (s[i] = 'u') then
      inc(x);
  end;
  for i := 1 to Length(t) do begin
    if (t[i] = 'a') or (t[i] = 'o') or (t[i] = 'e') or (t[i] = 'i') or (t[i] = 'u') then
      inc(y);
  end;
  for i := 1 to Length(r) do begin
    if (r[i] = 'a') or (r[i] = 'o') or (r[i] = 'e') or (r[i] = 'i') or (r[i] = 'u') then
      inc(z);
  end;
  if (x = 5) and (y = 7) and (z = 5) then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.