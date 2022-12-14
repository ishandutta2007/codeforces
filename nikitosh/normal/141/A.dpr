program projectA;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s, t, r: string;
  a, b: array[1..1000] of Char;
  k, l, m, i, j, x, y: Integer;
  bool : boolean;

begin
  Readln(s);
  readln(t);
  readln(r);
  k := Length(s);
  l := Length(t);
  m := Length(r);
  x := 0;
  y := 0;
  if (k + l <> m) then
  begin
    Writeln('NO');
    exit;
  end;
  for i := 1 to Length(s) do begin
    Inc(x);
    a[x] := s[i];
  end;
  for i := 1 to Length(t) do begin
    Inc(x);
    a[x] := t[i];
  end;
  for i := 1 to Length(r) do begin
    Inc(y);
    b[y] := r[i];
  end;
  for i := 1 to x do begin
    bool := False;
    for j := 1 to y do begin
      if (a[i] = b[j]) then
      begin
        b[j] := ' ';
        bool := True;
        Break;
      end;
    end;
    if bool = False then
    begin
      Writeln('NO');
      exit;
    end;
  end;
  Writeln('YES');
  readln;
  readln;
end.