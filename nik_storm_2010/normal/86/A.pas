uses
  math;
var
  ans,l,r,x:int64;

function weight(x:int64):int64;
var
  power,mem,res,c:int64;
begin
  res:=0; mem:=x; power:=1;
  while (x<>0) do
  begin
    c:=x mod 10;
    c:=9-c;
    res:=res+c*power;
    power:=power*10;
    x:=x div 10;
  end;
  weight:=res*mem;
end;

begin
  readln(l,r);
  ans:=max(weight(l),weight(r));
  x:=5;
  while (x<=r) do
  begin
    if (l<=x) and (x<=r) then ans:=max(ans,weight(x));
    x:=x*10;
  end;
  writeln(ans);
end.