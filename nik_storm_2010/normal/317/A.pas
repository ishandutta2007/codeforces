var
  ans,k,x,y,m:int64;


procedure outputdata(ans:int64);
begin
  writeln(ans); halt;
end;


begin

  readln(x,y,m); if (x>=m) or (y>=m) then outputdata(0);
  if (x<=0) and (y<=0) then outputdata(-1);
  if (x<0) then
  begin
    k:=(-x+y-1) div y; ans:=k;
    x:=x+k*y;
  end;
  if (y<0) then
  begin
    k:=(-y+x-1) div x; ans:=k;
    y:=y+k*x;
  end;
  while (x<m) and (y<m) do
  begin
    if x<y then begin x:=x+y; inc(ans); end
           else begin y:=x+y; inc(ans); end;
  end;
  writeln(ans);

end.