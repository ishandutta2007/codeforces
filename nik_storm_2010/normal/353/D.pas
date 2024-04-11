uses
  math;
var
  girl,wait,ans,d,i:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  for i:=d downto 1 do if (s[i]='F') then
  begin
    inc(girl);
    dec(wait);
    wait:=max(wait,0);
  end
    else
  begin
    ans:=girl+wait;
    if (girl<>0) then inc(wait);
  end;
  writeln(ans);
end.