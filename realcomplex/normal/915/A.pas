var
  n,k,cur,i,ans:longint;
begin
  readln(n,k);
  ans := 100000000;
  for i:=1 to n do
  begin
    read(cur);
    if k mod cur = 0 then
    begin
      cur := k div cur;
      if cur<ans then ans:=cur;
    end;
  end;
  writeln(ans);
end.