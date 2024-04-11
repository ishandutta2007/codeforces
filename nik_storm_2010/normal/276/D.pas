uses math;
var
    a:array[1..2,1..64] of int64; ans,tek,l,r:int64; i:longint;


procedure razlog(c:int64; nom:longint);
var tek:longint;
begin
  tek:=1;
  while c<>0 do
    begin
      a[nom,tek]:=c mod 2;
      c:=c div 2; inc(tek);
    end;
end;


begin

  readln(l,r); razlog(l,1); razlog(r,2);
  ans:=-1;
  for i:=64 downto 1 do
    if a[1,i]<>a[2,i] then
    begin
      ans:=i; break;
    end;
  if ans=-1 then writeln(0) else
  begin
    tek:=1;
    for i:=1 to ans do tek:=tek*2;
    writeln(tek-1);
  end;

end.