uses
  math;
var
  rr,ll,a:array[0..200000] of int64;
  ans,cur,n,l,r,ql,qr:int64;
  i,y:longint;

begin
  readln(n,l,r,ql,qr);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do ll[i]:=ll[i-1]+a[i]*l;
  for i:=n downto 1 do rr[i]:=rr[i+1]+a[i]*r;
  ans:=trunc(1e18);
  for i:=0 to n do
  begin
    y:=n-i;
    cur:=ll[i]+rr[i+1];
    if (abs(i-y))>1 then
    begin
      if (i>y) then cur:=cur+ql*(i-y-1) else cur:=cur+qr*(y-i-1);
    end;
    ans:=min(ans,cur);
  end;
  writeln(ans);
end.