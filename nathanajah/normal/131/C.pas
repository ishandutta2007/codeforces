var
n,m,t:longint;
c:array[0..100,0..100] of int64;
i,j:longint;
total:int64;

begin
for i:=0 to 50 do
begin
  c[i,i]:=1;
  c[i,0]:=1;
end;
for i:=0 to 50 do
  for j:=1 to i-1 do
    c[i,j]:=c[i-1,j-1]+c[i-1,j];
readln(n,m,t);
for i:=4 to t-1 do
  total:=total+c[n,i]*c[m,t-i];
writeln(total);
end.