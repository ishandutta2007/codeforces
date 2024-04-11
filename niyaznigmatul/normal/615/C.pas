
var
  s, t : array[0 .. 12345] of char;
  ax, ay, f, best, len : array[0 .. 12345] of longint;
  j, half, tt, n, m, i, mx, r, ac : longint;
  ch : char;

begin
  n := 0;
  read(ch);
  while ord(ch) <= 32 do read(ch);
  while ord(ch) > 32 do begin
    s[n] := ch;
    inc(n);
    read(ch);
  end;
  m := 0;
  while ord(ch) <= 32 do read(ch);
  while ord(ch) > 32 do begin
    t[m] := ch;
    inc(m);
    read(ch);
  end;
  for i := 0 to n - 1 do s[n + i + 1] := s[n - i - 1];
  s[n] := '#';
  n := 2 * n + 1;
  for i := 0 to n - 1 do f[i] := 0;
  for i := 0 to m - 1 do begin
    for j := n - 1 downto 1 do begin
      if t[i] <> s[j] then begin
        f[j] := 0;
      end else f[j] := f[j - 1] + 1;
    end;
    f[0] := 0;
    if (s[0] = t[i]) then f[0] := 1;
    mx := -1;
    for j := 0 to n - 1 do 
      if (mx < 0) or (f[mx] < f[j]) then mx := j;
    best[i] := mx;
    len[i] := f[mx];
  end;
  r := m;
  ac := 0;
  half := n div 2;
  while r > 0 do begin
    ax[ac] := best[r - 1] - len[r - 1] + 1;
    if len[r - 1] = 0 then begin
      writeln(-1);
      halt(0);
    end;
    ay[ac] := best[r - 1];
    if ax[ac] >= half then begin
      ax[ac] := ax[ac] - half - 1;
      ay[ac] := ay[ac] - half - 1;
      ax[ac] := half - ax[ac] - 1;
      ay[ac] := half - ay[ac] - 1;
    end;
    r := r - len[r - 1];
    inc(ac);
  end;
  writeln(ac);
  for i := ac - 1 downto 0 do begin
    writeln(ax[i] + 1, ' ', ay[i] + 1);
  end;
end.