

var
    n, i, len, j : integer;
    ch : char;
    s : array [0 .. 2222] of char;
    c : array [0 .. 2222, 0 .. 2222] of int64;
    ip :array [0 .. 2222, 0 .. 2222] of boolean; 
    ans : int64;
    
begin
  n := 0;
  read(ch);
  while not (ch in ['a' .. 'z']) do read(ch);
  while (ch in ['a' .. 'z']) do begin
    s[n] := ch;
    inc(n);
    read(ch);
  end;
  for i := 0 to n - 1 do begin
    ip[i][i] := true;
    c[i][i] := 1;
  end;
  for i := 0 to n - 2 do begin
    if s[i] = s[i + 1] then  begin
        ip[i][i + 1] := true;
        c[i][i + 1] := 3;
    end else c[i][i + 1] := 2;
  end;
  for len := 2 to n - 1 do begin
    for i := 0 to n - len - 1 do begin
      j := i + len;
      ip[i][j] := ip[i + 1][j - 1] and (s[i] = s[j]);
      c[i][j] := c[i + 1][j] + c[i][j - 1] - c[i + 1][j - 1];
      if (ip[i][j]) then inc(c[i][j]);
    end;
  end;
  ans := 0;
  for i := 0 to n - 1 do
      for j := i to n - 2 do
          if (ip[i][j]) then
              ans := ans + c[j + 1][n - 1];
  writeln(ans);
end.