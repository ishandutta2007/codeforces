var
    a,step:array[0..1000000] of int64; i,j:longint; n:int64;


begin

  readln(n); step[0]:=1;
  for i:=1 to 31 do step[i]:=step[i-1]*2;
  for i:=0 to 31 do step[i]:=step[i]-1;
  for i:=n downto 0 do
    if a[i]=0 then
    begin
      j:=0; while (i>step[j]) do inc(j);
      a[i]:=step[j] xor i;
      a[step[j] xor i]:=i;
    end;
  writeln(n*(n+1));
  for i:=0 to n do write(a[i],' ');

end.