uses
  math;
var
  k:array[0..4] of longint;
  n,i,x,sum,ans:longint;

begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    sum:=sum+x;
    inc(k[x]);
  end;
  if (sum in [1,2,5]) then begin writeln(-1); halt; end;
  x:=min(k[1],k[2]);
  ans:=x;
  k[3]:=k[3]+x;
  k[1]:=k[1]-x;
  k[2]:=k[2]-x;
  if (k[1]<>0) then
  begin
    ans:=ans+k[1]-k[1] div 3;
    if (k[1]=1) and (k[3]=0) then inc(ans);
  end;
  if (k[2]<>0) then
  begin
    x:=k[2] div 3;
    ans:=ans+x*2;
    k[2]:=k[2] mod 3;
    if (k[2]<>0) then if (k[2]=1) and (k[4]<>0) then inc(ans) else ans:=ans+2;
  end;
  writeln(ans);

end.