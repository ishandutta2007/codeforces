const max=100000;
var
  a:array[1..max] of longint; ans:array[1..max] of char; cur,n,i:longint; flag:boolean;


begin
  readln(n); for i:=1 to n do read(a[i]);
  cur:=0;
  for i:=n downto 1 do if (cur>0) then cur:=cur-a[i] else cur:=cur+a[i];
  if cur>0 then flag:=true else flag:=false;
  cur:=0;
  for i:=n downto 1 do
    if (cur>0) then
    begin
      cur:=cur-a[i];
      if (flag) then ans[i]:='-' else ans[i]:='+';
    end
      else
    begin
      cur:=cur+a[i];
      if (flag) then ans[i]:='+' else ans[i]:='-';
    end;
  for i:=1 to n do write(ans[i]);
end.