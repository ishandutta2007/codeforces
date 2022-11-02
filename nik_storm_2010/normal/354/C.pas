uses
  math;
const
  ll=1000000;
var
  cnt:array[0..ll] of longint;
  n,k,x,y,l,i,j,sum,ans:longint;

begin
  readln(n,k);
  l:=maxlongint;
  for i:=1 to n do
  begin
    read(x);
    l:=min(l,x);
    inc(cnt[x]);
  end;
  for i:=1 to ll do cnt[i]:=cnt[i-1]+cnt[i];
  if (l<=k+1) then begin writeln(l); halt; end;
  for i:=k+1 to l do
  begin
    sum:=0;
    for j:=1 to ll do
    begin
      if (j*i>ll) then break;
      x:=j*i;
      y:=j*i+k;
      y:=min(y,ll);
      sum:=sum+cnt[y]-cnt[x-1];
    end;
    if (sum=n) then ans:=i;
  end;
  writeln(ans);
end.