var
    ans:array[1..1000000] of longint; s:ansistring; d,l,r,i:longint;


begin

  readln(s); d:=length(s); l:=1; r:=d;
  for i:=1 to d do
    if s[i]='l' then
    begin
      ans[r]:=i; dec(r);
    end
      else
    begin
      ans[l]:=i; inc(l);
    end;
  for i:=1 to d do write(ans[i],' ');

end.