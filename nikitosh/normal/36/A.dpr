program Project36A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n, k, l: Integer;
  b: Boolean;
  a: array[1..100] of Integer;
  s: string;

begin
  Reset(input, 'input.txt');
  Rewrite(Output, 'output.txt');
  b := True;
  k := 0;
  readln(n);
  Readln(s);
  for i := 1 to n do begin
    if s[i] = '1' then
    begin
      inc(k);
      a[k] := i;
    end;
  end;
  l := a[2] - a[1];
  for i := 3 to k do begin
    if a[i] - a[i - 1] <> l then
    begin
      b := false;
      Break;
    end;
  end;
  if b = true then
    Writeln('YES')
  else
    writeln('NO');
  Readln;
  readln;
end.