program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
type cell = record
  s2, s5 : longint;
  is_null : boolean;
end;
var i, j, x, n, answ, y : longint;
    a : array [1..1000, 1..1000] of cell;
    a2, a5 : array [1..1000, 1..1000] of longint;
    any_nulls : boolean;
    answer : string;
//
function step(n, x : longint):longint;
var answ : longint;
begin
answ := 0;
while (n mod x = 0) and (n<>0) do begin
  inc(answ);
  n := n div x;
end;
result := answ;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
Readln(n);
for i := 1 to n do
  for j := 1 to n do begin
    Read(x);
    a[i, j].s2 := step (x, 2);
    a[i, j].s5 := step (x, 5);
    if (x=0) then begin a[i, j].is_null := true; any_nulls := true; end;
  end;
// s2
a2[1, 1] := a[1, 1].s2;
for i := 2 to n do
  a2[1, i] := a2[1, i-1]+a[1, i].s2;
for i := 2 to n do begin
  a2[i, 1] := a[i, 1].s2 + a2[i-1, 1];
  for j := 2 to n do
    a2[i, j] := a[i, j].s2+Math.Min(a2[i-1, j], a2[i, j-1]);
end;
// s5
a5[1, 1] := a[1, 1].s5;
for i := 2 to n do
  a5[1, i] := a5[1, i-1]+a[1, i].s5;
for i := 2 to n do begin
  a5[i, 1] := a[i, 1].s5 + a5[i-1, 1];
  for j := 2 to n do
    a5[i, j] := a[i, j].s5+Math.Min(a5[i-1, j], a5[i, j-1]);
end;
//
answ := Math.Min(a2[n, n], a5[n, n]);
if ((any_nulls) and (answ > 1)) then begin
  for i := 1 to n do
    for j := 1 to n do
      if (a[i, j].is_null) then begin x := j; y := i; end;
  Writeln(1);
  for i := 1 to x-1 do Write('R');
  for i := 1 to n-1 do Write('D');
  for i := x to n-1 do Write('R');
end else begin
  Writeln(answ);
  if (a2[n, n]=answ) then begin
    answer := '';
    x := n; y := n;
    while (x<>1) or (y<>1) do begin
      if ((y<>1) and ((x=1) or (a2[y, x-1]>=a2[y-1, x]))) then
        begin
          answer := 'D'+answer;
          y := y-1;
        end else begin
          answer := 'R'+answer;
          x := x-1;
        end;
    end;
  end else begin
    answer := '';
    x := n; y := n;
    while (x<>1) or (y<>1) do begin
      if ((y<>1) and (((x=1) or (a5[y, x-1]>=a5[y-1, x])))) then
        begin
          answer := 'D'+answer;
          y := y-1;
        end else begin
          answer := 'R'+answer;
          x := x-1;
        end;
    end;
  end;
  Writeln(answer);
end;
//
//close(input);
end.