var
  r,h,l:int64;

begin
  readln(r,h);
  l:=h div r;
  if (h-l*r>=r/2) then l:=l+1;
  if (sqrt((r/2)*(r/2)+(h+r-l*r)*(h+r-l*r))>=r) then writeln(l*2+1) else writeln(l*2);
end.