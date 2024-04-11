var
    a:array[1..4,1..4] of longint; i,j:longint; c:char;


begin

  for i:=1 to 4 do
    begin
      for j:=1 to 4 do
        begin
          read(c); if c='#' then a[i,j]:=1 else a[i,j]:=0;
        end;
      readln;
    end;
  for i:=2 to 4 do
    for j:=2 to 4 do
    if a[i,j]+a[i-1,j]+a[i,j-1]+a[i-1,j-1]<>2 then
    begin
      writeln('YES');
      halt;
    end;
  writeln('NO');

end.