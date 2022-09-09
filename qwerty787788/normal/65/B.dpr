program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
var i, N, last, x, j, add, x1, x2, x3, x4 :longint;
    a: array [1..1000] of longint;
    ok, ok1 :boolean;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(N); last := 999; ok := true;
for i := 1 to N do readln(a[i]);
for i := 1 to N do begin
  x1 := StrToInt(copy(IntToStr(a[i]), 1, 1));
  x2 := StrToInt(copy(IntToStr(a[i]), 2, 1));
  x3 := StrToInt(copy(IntToStr(a[i]), 3, 1));
  x4 := StrToInt(copy(IntToStr(a[i]), 4, 1));
  a[i] := 9999;
  for j := 1 to 2 do
    if ((j*1000+x2*100+x3*10+x4)>=last) and ((j*1000+x2*100+x3*10+x4)<=2011) and ((j*1000+x2*100+x3*10+x4)<=a[i]) then a[i] := (j*1000+x2*100+x3*10+x4);
  for j := 0 to 9 do
    if ((x1*1000+j*100+x3*10+x4)>=last) and ((x1*1000+j*100+x3*10+x4)<=2011) and ((x1*1000+j*100+x3*10+x4)<=a[i]) then a[i] := (x1*1000+j*100+x3*10+x4);
  for j := 0 to 9 do
    if ((x1*1000+x2*100+j*10+x4)>=last) and ((x1*1000+x2*100+j*10+x4)<=2011) and ((x1*1000+x2*100+j*10+x4)<=a[i]) then a[i] := (x1*1000+x2*100+j*10+x4);
  for j := 0 to 9 do
    if ((x1*1000+x2*100+x3*10+j)>=last) and ((x1*1000+x2*100+x3*10+j)<=2011) and ((x1*1000+x2*100+x3*10+j)<=a[i]) then a[i] := (x1*1000+x2*100+x3*10+j);    
  if (a[i] = 9999) then ok := false;
  last := a[i];
end;
if (not ok) then Writeln('No solution') else begin
  for i := 1 to N do Writeln(a[i]);
end;
//
//close(input);
end.