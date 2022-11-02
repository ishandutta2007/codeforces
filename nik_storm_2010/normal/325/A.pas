var
  x1,y1,x2,y2:array[1..100] of longint; sum,n,i:longint;


procedure solve(x,y:longint);
var i,xx,yy:longint;
begin
  xx:=x+round(sqrt(sum)); yy:=y+round(sqrt(sum));
  for i:=1 to n do
  begin
    if (x<=x1[i]) and (x2[i]<=xx) then else exit;
    if (y<=y1[i]) and (y2[i]<=yy) then else exit;
  end;
  writeln('YES'); halt;
end;


begin

  readln(n); sum:=0;
  for i:=1 to n do
  begin
    readln(x1[i],y1[i],x2[i],y2[i]);
    sum:=sum+abs(x1[i]-x2[i])*abs(y1[i]-y2[i]);
  end;
  if frac(sqrt(sum))<>0 then writeln('NO') else
  begin
    for i:=1 to n do
    begin
      solve(x1[i],y1[i]);
      solve(x2[i],y2[i]);
    end;
    writeln('NO');
  end;

end.