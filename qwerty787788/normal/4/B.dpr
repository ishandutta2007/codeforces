program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var a : array [1..30, 1..2] of longint;
    d, sumTime, minSum, maxSum, i, add : longint;
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(d, sumTime); minSum := 0; maxSum := 0;
for i := 1 to d do begin
  Readln(a[i, 1], a[i, 2]);
  inc(minSum, a[i, 1]);
  inc(maxSum, a[i, 2]);
end;
//
if (minSum <= sumTime) and (maxSum >= sumTime) then begin
  Writeln('YES');
  add := sumTime - minSum;
  for i := 1 to d do
    if (a[i, 2]-a[i, 1] > add) then begin
      Write(a[i, 1]+add, ' ');
      add := 0;
    end else begin
      add := add - (a[i, 2]-a[i, 1]);
      Write(a[i, 2], ' ');
    end;
end else Writeln('NO');
//
//close(input);
end.