program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, m, i, min, x, y : longint;
    cost : array [1..100] of longint;
    p : array [1..100, 1..100] of boolean;    
//
begin
Readln(n, m);
min := MaxInt;
for i := 1 to n do read(cost[i]);
for i := 1 to m do begin
  Readln(x, y);
  p[x, y] := true;
  p[y, x] := true;
end;
for i := 1 to n-2 do
  for x := i+1 to n-1 do
    for y := x+1 to n do
      if ((p[i, x]) and (p[i, y]) and (p[x, y])) then
        if (cost[i]+cost[x]+cost[y]<min) then
          min := cost[i]+cost[x]+cost[y];
if (min = MaxInt) then Writeln(-1) else Writeln(min);
end.