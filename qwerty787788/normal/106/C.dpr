program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
var a : array [0..1000, 0..11] of longint;
    cost, need, need2 : array [1..11] of longint;
    n, m, i, j, max, k : longint;
begin
//assign(input, 'input.txt'); reset(input);
//
Read(n, m);
Read(need[m+1], cost[m+1]); need2[m+1] := 0;
//
for i := 1 to m do
  Read(a[0, i], need2[i], need[i], cost[i]);
//
for i := 0 to n do
  for j := 1 to m+1 do
    if ((i+need[j]<=n) and (a[i, j] >= need2[j])) then
      if (a[i+need[j], 0] < a[i, 0]+cost[j]) then begin
        a[i+need[j], 0] := a[i, 0]+cost[j];
        for k := 1 to m do
          a[i+need[j], k] := a[i, k];
        a[i+need[j], j] := a[i, j]-need2[j];
      end;
//
max := 0;
for i := 0 to n do
  if (a[i, 0] > max) then max := a[i, 0];
Writeln(max);
//
//close(input);
end.