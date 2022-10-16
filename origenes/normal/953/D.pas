const
  maxn = 10;

var
  s:array[1..maxn] of string;
  f:array[1..maxn, 1..maxn] of longint;
  i, j: longint;
  maxm, r, c: longint;
begin
  for i := 1 to 6 do
  begin
    readln(s[i])
  end;
  
  
  for i := 1 to 6 do
  begin
    f[i][1] := (8 - i) div 2;
    f[i][2] := (8 - i) div 2;
    f[i][7] := (8 - i) div 2;
    f[i][8] := (8 - i) div 2;
    f[i][4] := (10 - i) div 2;
    f[i][5] := (10 - i) div 2;
  end;
  
  for i := 1 to 6 do
    for j := 1 to 8 do
    begin
      if (f[i][j] > maxm) and (s[i][j] <> '*') then
      begin
        maxm := f[i][j];
        r := i;
        c := j;
      end;
    end;
  
  s[r][c] := 'P';
  for i := 1 to 6 do
  begin
    writeln(s[i]);
  end;
end.