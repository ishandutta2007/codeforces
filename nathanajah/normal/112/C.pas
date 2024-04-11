var
n,x,y:int64;
i:longint;
sum:int64;

begin
readln(n,x,y);
sum:=(n-1)+(y+1-n)*(y+1-n);
if (sum<x) or (n>y) then writeln(-1)
else
begin
  for i:=1 to n-1 do
    writeln(1);
  writeln(y+1-n);
end;
end.