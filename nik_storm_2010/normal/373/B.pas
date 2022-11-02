var
  w,m,k,l,r,mid:int64;

function count(x:int64):int64;
var
  i:longint;
  res,lim:int64;
begin
  lim:=10;
  res:=1;
  for i:=1 to 18 do
  begin
    if (lim-1>=x) then begin res:=res+(x-lim div 10+1)*i; break; end;
    res:=res+(lim-lim div 10)*i;
    lim:=lim*10;
  end;
  count:=res;
end;

begin
  readln(w,m,k);
  w:=w div k;
  l:=0; r:=w+1;
  while (r-l>1) do
  begin
    mid:=(l+r) div 2;
    if (count(m+mid-1)-count(m-1)<=w) then l:=mid else r:=mid;
  end;
  writeln(l);
end.