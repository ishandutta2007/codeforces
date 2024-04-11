
var ans, n, m, q, i, j, v, u, c : longint;
p : array[0 .. 1234567] of longint;
function get(x : longint) : longint;
begin
  if x <> p[x] then p[x] := get(p[x]);
  result := p[x];
end;

begin
  read(n, m);
  for i := 0 to m do
    for j := 0 to n - 1 do p[i * n + j] := i * n + j;
  for i := 1 to m do begin
    read(v, u, c);
    dec(v);
    dec(u);
    p[get(c * n + v)] := get(c * n + u);
  end;
  read(q);
  for i := 1 to q do begin
    read(v, u);
    dec(v);
    dec(u);
    ans := 0;
    for j := 1 to m do begin
      if get(j * n + v) = get(j * n + u) then inc(ans);
    end;
    writeln(ans);
  end;
end.