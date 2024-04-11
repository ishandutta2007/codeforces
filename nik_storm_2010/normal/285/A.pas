var
    n,k,i:longint;


begin

  readln(n,k);
  for i:=k+1 downto 1 do write(i,' ');
  for i:=k+2 to n do write(i,' ');

end.