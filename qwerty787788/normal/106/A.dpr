program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const alph = '23456789TJQKA';
var n1, n2, max, answ :longint;
    k, a, b, c, d, e : char;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(k);
Readln(a, b, c, d, e);
//
n1 := pos(a, alph);
n2 := pos(d, alph);
if (e=k) then begin
  if (b <> k ) then answ := 0 else
  if (n1 > n2) then answ := 1 else answ := 0;
end else begin
  if (b = k) then answ :=1 else
  if (b <> e) then answ := 0 else
  if (n1 > n2) then answ := 1;
end;
if (answ=1) then Writeln('YES') else Writeln('NO');
//
//close(input);
end.