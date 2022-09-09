program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type vector = record
  x, y : int64;
end;
var a, b, c : vector;
//
function minus(a, b:vector):vector;
var c : vector;
begin
c.x := a.x - b.x;
c.y := a.y - b.y;
minus := c;
end;
//
function round_(a:vector):vector;
var c : vector;
begin
c.x := -a.y;
c.y := a.x;
round_ := c;
end;
//
function answ(a1, a2 : vector):boolean;
var alpha, betta : double;
begin
if ((a1.x=0)and(a1.y=0)) then begin
  if ((a2.x=0)and(a2.y=0)) then answ := true else answ := false;
end else begin
  alpha := (a1.x*a2.x+a2.y*a1.y)/(a1.x*a1.x+a1.y*a1.y);
  betta := (a2.x*a1.y-a1.x*a2.y)/(a1.x*a1.x+a1.y*a1.y);
  if ((abs(round(alpha)-alpha)<0.000000001) and
     (abs(round(betta)-betta)<0.000000001)) then
     answ := true else
     answ := false;
end;
end;
//
begin
Readln(a.x, a.y);
Readln(b.x, b.y);
Readln(c.x, c.y);
//
//
if (
    (answ(c, minus(b, a)))  or
    (answ(c, minus(b, round_(a))))  or
    (answ(c, minus(b, round_(round_(a))))) or
    (answ(c, minus(b, round_(round_(round_(a))))))
   ) then
  Writeln('YES') else Writeln('NO');
end.