type
  zji=record
       f1,f2,f3:int64;
       num1,num2,num3:longint;
     end;
var
  n,tot:longint;
  a:array [1..1000000] of longint;
  zj:array [1..1000000] of zji;
  dp:array [0..1,1..1000000] of int64;
function max(x,y:int64):int64;
begin
  if x>y then exit(x)
  else exit(y);
end;
procedure init;
var
  i:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  i:=1;
  inc(tot); zj[tot].f2:=a[1]; zj[tot].num2:=1; zj[tot].f3:=a[2]; zj[tot].num3:=2;
  while i<n do
  begin
    if a[i+1]-a[i]<=0 then
    begin
      while (i<n) and (a[i+1]-a[i]<=0) do inc(i);
    end
    else
    begin
      while (i<n) and (a[i+1]-a[i]>0) do inc(i);
    end;
    inc(tot); zj[tot].f2:=a[i]; zj[tot].num2:=i; zj[tot].f1:=a[i-1]; zj[tot].num1:=i-1;
    if i<>n then
    begin
      zj[tot].f3:=a[i+1];
      zj[tot].num3:=i+1;
    end;
  end;
  for i:=2 to tot do
  begin
    dp[0,i]:=dp[0,i-1]+abs(zj[i].f1-zj[i-1].f2);
    if zj[i].num1>=zj[i-1].num3 then
    dp[0,i]:=max(dp[0,i],dp[1,i-1]+abs(zj[i].f1-zj[i-1].f3))
    else dp[0,i]:=max(dp[0,i],dp[1,i-1]);
    dp[1,i]:=max(dp[0,i-1]+abs(zj[i].f2-zj[i-1].f2),dp[1,i-1]+abs(zj[i].f2-zj[i-1].f3));
  end;
  writeln(max(dp[0,tot],dp[1,tot]));
end;
begin
  init;
end.