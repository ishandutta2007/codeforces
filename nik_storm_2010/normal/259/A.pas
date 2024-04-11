var
    a:array[1..8,1..8] of char; i,j:longint;


begin

  for i:=1 to 8 do
    begin
      for j:=1 to 8 do read(a[i,j]);
      readln;
    end;
  for i:=1 to 8 do
    for j:=2 to 8 do
    if a[i,j-1]=a[i,j] then
      begin
        writeln('NO');
        halt;
      end;
  writeln('YES');

end.