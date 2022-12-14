program ProjectF;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s, t: string;
  a, i, j, g, k, l: Integer;
  b: array[1..100000] of Integer;

function prost(d: Integer): Integer;

var
  ii: Integer;

begin
  l := 0;
  for ii := 2 to Trunc(Sqrt(d)) + 1 do begin
    if (d mod ii = 0) then
    begin
      l := 1;
      break;
    end;
  end;
  if (l = 0) then
    Result := 1
  else
    Result := 0;
end;

begin
  read(a);
  k := 0;
  for i := 2 to 1000000 do begin
    s := IntToStr(i);
    if (s[1] = '2') or (s[1] = '4') or (s[1] = '6') or (s[1] = '8') or (s[1] = '5') then
      Continue;
    t := '';
    for g := 1 to Length(s) do begin
      t := t + s[Length(s) - g + 1];
    end;
    if (t[1] = '0') or (t[1] = '2') or (t[1] = '4') or (t[1] = '6') or (t[1] = '8') or (t[1] = '5') then
      Continue;
    j := StrToInt(t);
    if (prost(i) = 1) and (prost(j) = 1) and (i <> j) then
    begin
      Inc(k);
      b[k] := i;
    end;
    if (k > 11185) then
      break;
  end;
  Writeln(b[a]);
  Readln;
  readln;
end.