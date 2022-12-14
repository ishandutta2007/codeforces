program Project75A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, a, b, c, k: integer;
  s, t, r: string;

begin
  k := 0;
  Readln(s);
  Readln(t);
  a := StrToInt(s);
  b := StrToInt(t);
  c := a + b;
  r := IntToStr(c);
  for i := 1 to Length(s) do begin
    if s[i] <> '0' then
    begin
      Inc(k);
      s[k] := s[i];
    end;
  end;
  Delete(s, k + 1, Length(s) - k);
  k := 0;
  for i := 1 to Length(t) do begin
    if t[i] <> '0' then
    begin
      Inc(k);
      t[k] := t[i];
    end;
  end;
  Delete(t, k + 1, Length(t) - k);
  k := 0;
  for i := 1 to Length(r) do begin
    if r[i] <> '0' then
    begin
      Inc(k);
      r[k] := r[i];
    end;
  end;
  Delete(r, k + 1, Length(r) - k);
  a := StrToInt(s);
  b := StrToInt(t);
  c := StrToInt(r);
  if a + b = c then
    Writeln('YES')
  else
    Writeln('NO');
  readln;
  readln;
end.