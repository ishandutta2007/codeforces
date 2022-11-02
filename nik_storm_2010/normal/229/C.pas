const
  l=1000000;
var
  cnt:array[1..l] of int64;
  ans,n,m,x,y:int64;
  i:longint;

begin
  readln(n,m);
  for i:=1 to n do cnt[i]:=n-1;
  for i:=1 to m do
  begin
    readln(x,y);
    dec(cnt[x]);
    dec(cnt[y]);
  end;
  ans:=0;
  for i:=1 to n do
  begin
    x:=cnt[i];
    y:=n-1-cnt[i];
    ans:=ans+(+2)*x*(x-1) div 2;
    ans:=ans+(+2)*y*(y-1) div 2;
    ans:=ans+(-1)*x*y;
  end;
  writeln(ans div 6);
end.