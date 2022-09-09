program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;

type point = record
  x, y : extended;
end;
var i, points : longint;
    p1, p2, p3 : point;
    A1, B1, C1, A2, B2, C2, Anew, Bnew, Cnew, x_center, y_center, angle, angle1, angle2, angle3, angle12, angle13, angle23, answer, a : extended;
    ok : boolean;
//
function div_ok(x, y : extended) : boolean;
begin
if (abs(round(x/y)-x/y)<1e-5) then result := true else result := false;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
Readln(p1.x, p1.y);
Readln(p2.x, p2.y);
Readln(p3.x, p3.y);
//
A1 := p1.y - p2.y;
B1 := p2.x - p1.x;
C1 := p2.y*(-B1)+p2.x*(A1);
Anew := B1;
Bnew := -A1;
Cnew :=  -(Anew*(p1.x+p2.x)/2+Bnew*(p1.y+p2.y)/2);
A1 := Anew;
B1 := Bnew;
C1 := Cnew;
//
A2 := p1.y - p3.y;
B2 := p3.x - p1.x;
C2 := p3.y*(-B2)+p3.x*(A2);
Anew := B2;
Bnew := -A2;
Cnew :=  -(Anew*(p1.x+p3.x)/2+Bnew*(p1.y+p3.y)/2);
A2 := Anew;
B2 := Bnew;
C2 := Cnew;
//
x_center := (-C1*B2 + C2*B1)/(A1*B2 - B1*A2);
y_center := (-C1*A2 + C2*A1)/(B1*A2 - b2*A1);
//
points := 2;
angle1 := ArcTan2(p1.y-y_center, p1.x-x_center); if (angle1<0) then angle1 := angle1 + 2*PI;
angle2 := ArcTan2(p2.y-y_center, p2.x-x_center); if (angle2<0) then angle2 := angle2 + 2*PI;
angle3 := ArcTan2(p3.y-y_center, p3.x-x_center); if (angle3<0) then angle3 := angle3 + 2*PI;
angle12 := abs(angle1-angle2);
angle13 := abs(angle1-angle3);
angle23 := abs(angle3-angle2);
ok :=false;
while (not ok) do begin
  inc(points);
  angle := 2*PI/points;
  if ((div_ok(angle12, angle)) and (div_ok(angle13, angle)) and (div_ok(angle23, angle)))
    then ok := true;
end;
//
a := sqrt((p1.x-x_center)*(p1.x-x_center)+(p1.y-y_center)*(p1.y-y_center));
answer:=0.5*points*a*a*sin(angle);
//
Writeln(answer:0:6);
//
//close(input);
end.