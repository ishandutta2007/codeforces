var
    a:array[1..100000] of longint; n,i:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  for i:=n-1 downto 1 do
    if a[i]>a[i+1] then
    begin
      writeln(i);
      halt;
    end;
  writeln(0);

end.