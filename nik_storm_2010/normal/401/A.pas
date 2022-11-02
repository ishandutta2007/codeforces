uses
  math;
var
  sum,ans,n,x,i,z:longint;

begin
  readln(n,x);
  sum:=0;
  for i:=1 to n do
  begin
    read(z);
    sum:=sum+z;
  end;
  ans:=0;
  while (sum<>0) do
  begin
    if (sum<0) then sum:=min(sum+x,0) else sum:=max(0,sum-x);
    inc(ans);
  end;
  writeln(ans);
end.