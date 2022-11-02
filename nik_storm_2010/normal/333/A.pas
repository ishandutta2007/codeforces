var
  step:array[0..36] of int64; n,k:int64; nom,i:longint;


begin
  readln(n); k:=n;
  step[0]:=1; for i:=1 to 36 do step[i]:=step[i-1]*3;
  for i:=36 downto 0 do
  begin
    while k>=step[i] do
    begin
      nom:=i;
      k:=k-step[i];
    end;
  end;
  writeln(n div step[nom+1]+1);

end.