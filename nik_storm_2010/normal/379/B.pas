var
  a:array[1..100000] of longint;
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    while (a[i]<>0) do
    begin
      if (i=n) then write('LR') else write('RL');
      write('P');
      dec(a[i]);
    end;
    if (i<>n) then write('R');
  end;
end.