uses
  math;
const
  l=4194303;
  log=21;
var
  a,res:array[0..l] of longint;
  n,i,j,x:longint;

begin
  for i:=0 to l do res[i]:=-1;
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    x:=0;
    for j:=0 to log do if (a[i] and (1 shl j)=0) then x:=x xor (1 shl j);
    res[x]:=a[i];
  end;
  for i:=l downto 0 do
  begin
    if (res[i]<>-1) then continue;
    for j:=0 to log do if (i and (1 shl j)=0) then res[i]:=max(res[i],res[i xor (1 shl j)]);
  end;
  for i:=1 to n do write(res[a[i]],' ');
end.