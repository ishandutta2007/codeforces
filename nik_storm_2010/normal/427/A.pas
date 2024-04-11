var
  n,ans,cnt,x,i:longint;

begin
  readln(n);
  cnt:=0;
  ans:=0;
  for i:=1 to n do
  begin
    read(x);
    if (x=-1) then
    begin
      if (cnt=0) then inc(ans) else dec(cnt);
    end
    else cnt:=cnt+x;
  end;
  writeln(ans);
end.