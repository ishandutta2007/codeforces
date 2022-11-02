const base=1000000007;
var
  t:array[0..100000] of int64; s:ansistring; ans,cur,d,k:int64; i:longint;


function step(x,y:int64):int64;
var c:int64;
begin
  if y=0 then step:=1;
  if y=1 then step:=x else
  begin
    c:=step(x,y div 2);
    if y mod 2=1 then step:=((((c*c)mod base)*x) mod base) else step:=(c*c) mod base;
  end;
end;


begin

  t[0]:=1;
  for i:=1 to 100000 do t[i]:=(t[i-1]*2) mod base;
  readln(s); readln(k);
  d:=length(s);
  ans:=0;
  for i:=d downto 1 do
  begin
    if (s[i]='0') or (s[i]='5') then ans:=(ans+t[i-1]) mod base;
  end;
  cur:=step(t[d],k);
  ans:=((((ans*(cur-1)) mod base) * step((t[d]-1),base-2)) mod base);
  writeln(ans mod base);

end.