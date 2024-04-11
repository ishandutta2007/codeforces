var a, b, s, i, j, z, kitten : longint;
 
q : array [1..10] of longint;
 
c : char;
begin
  readln(a, b, s);
  for i := 1 to a do
  begin
    for j := 1 to b - 1 do
    begin
      read(c);
      if c = 'Y' then
        inc(q[j]);
    end;
    readln(c);
    if c = 'Y' then
      inc(q[b]);
  end;
  for i := 1 to b do
    if q[i] >= s then
       inc(z);
  write(z);
end.