var
n:longint;
speed,ram,hdd,cost:array[1..100] of longint;
i,j:longint;
outdated:array[1..100] of boolean;
mincost,num:longint;

begin
mincost:=1000000;
readln(n);
for i:=1 to n do
  readln(speed[i],ram[i],hdd[i],cost[i]);
for i:=1 to n do
  if not outdated[i] then
    for j:=i+1 to n do
      if (speed[j]>speed[i]) and (ram[j]>ram[i]) and (hdd[j]>hdd[i]) then
      begin
        outdated[i]:=true;
        break;
      end
      else if (speed[j]<speed[i]) and (ram[j]<ram[i]) and (hdd[j]<hdd[i]) then
        outdated[j]:=true;
for i:=1 to n do
  if not outdated[i] then
    if cost[i]<mincost then
    begin
      num:=i;
      mincost:=cost[i];
    end;
writeln(num);
end.