program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type no = record
  speed, ram, hdd, cost : real;
  star : boolean;
end;
var N, i, j :longint;
    a : array [1..100] of no;
    answ : longint;
//
begin
//assign(input, 'input.txt'); reset(input);
//
REadln(N);
for i := 1 to N do  begin
  Readln(a[i].speed, a[i].ram, a[i].hdd, a[i].cost);
  a[i].star := false;
end;
for i := 1 to N do
  for j := 1 to N do
    if (i<>j) then
      if (a[i].speed < a[j].speed) and (a[i].ram < a[j].ram) and (a[i].hdd < a[j].hdd) then
        a[i].star := true;
//
answ := -1;
for i := 1 to N do
  if (a[i].star = false) then
    if (answ = -1) or (a[i].cost < a[answ].cost) then answ := i;
//
Writeln(answ);
//
//close(input);
end.