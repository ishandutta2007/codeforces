uses math; const size=5000;
var
  cnt:array[1..size] of longint; l1,l2,n,m,x,i,j:longint;


begin
  readln(n,m); readln(x);
  for i:=1 to n do for j:=1 to m do
  begin
    if (odd(i+j)) then continue;
    l1:=min(i,n-i+1); l2:=min(j,m-j+1);
    inc(cnt[min(l1,l2)]);
  end;
  if (x>size) then writeln(0) else writeln(cnt[x]);
end.