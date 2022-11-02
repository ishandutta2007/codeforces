uses math;
var
  a,b,ans:array[1..100000] of longint; all,cnt,i,j,n:longint;


begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=30 downto 0 do
  begin
    all:=-1;
    for j:=1 to n do if (a[j] and (1 shl i)<>0) then
    begin
      if (all=-1) then all:=a[j] else all:=all and a[j];
    end;
    if (all<>-1) and (all mod (1 shl i)=0) then
    begin
      for j:=1 to n do if (a[j] and (1 shl i)<>0) then
      begin
        inc(cnt);
        ans[cnt]:=a[j];
      end;
      writeln(cnt);
      for j:=1 to cnt do write(ans[j],' ');
      halt;
    end;
  end;
end.