var
n:longint;
a,b:longint;
i:longint;
count:longint;

begin
readln(n,a,b);
for i:=0 to b do
  if (n-1-i>=a) then
    count:=count+1;
writeln(count);
end.