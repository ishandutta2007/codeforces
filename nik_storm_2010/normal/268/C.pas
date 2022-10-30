uses math;
var
    ans,n,m,x,y:longint;


begin

  readln(n,m); writeln(min(n,m)+1);
  x:=n; y:=0;
  while true do
    begin
      writeln(x,' ',y);
      dec(x); if x<0 then break;
      inc(y); if y>m then break;
    end;

end.