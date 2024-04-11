program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;
// New types
type point = record
  x, y : extended;
end;
type circle = record
  center : point;
  r : extended;
end;
type line = record
  A, B, C : extended;
end;
type object_ = record
  type_ : byte; // 0 - circle; 1 - line
  circle : circle;
  line : line;
end;
//
const Eps : Real = 1e-5;
//
var i : longint;
    st : array [1..3] of circle;
    answ, answ1, answ2 : point;
    p1, p2 : object_;
    no_result : boolean;
//
function closer(p1, p2 : point):point;
begin
if (((p1.x-st[1].center.x)*(p1.x-st[1].center.x) + (p1.y-st[1].center.y)*(p1.y-st[1].center.y)) >=
    ((p2.x-st[1].center.x)*(p2.x-st[1].center.x) + (p2.y-st[1].center.y)*(p2.y-st[1].center.y))) then
    result := p2 else result := p1;
end;
//
function new_line(p1, p2 : point) : line;
var answ : line;
begin
answ.A := p1.y - p2.y;
answ.B := p2.x - p1.x;
answ.C := p2.y * (-answ.B) + p2.x * (answ.A);
result := answ;
end;
//
function normal(l : line; p1, p2 : point):line;
var answ : line;
begin
answ.A := l.B;
answ.B := -l.A;
answ.C := - (answ.A*(p1.x+p2.x)/2+answ.B*(p1.y+p2.y)/2);
result := answ;
end;
//
function distance(p1, p2 : point) : extended;
begin
result := sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
end;
//
function otn(p1, p2:point; k : extended):point;
var answ : point;
begin
answ.x := p1.x+(p2.x-p1.x)*k;
answ.y := p1.y+(p2.y-p1.y)*k;
result := answ;
end;
//
function middle (p1, p2:point):point;
var answ : point;
begin
answ.x := (p1.x+p2.x)/2;
answ.y := (p1.y+p2.y)/2;
result := answ;
end;
//
function cross(i1, i2 : longint) : object_;
var answ : object_;
    line1, line2 : line;
    f1, f2 : point;
    d, a, b, x : extended;
begin
if (st[i1].r = st[i2].r) then begin
  answ.type_ := 1;
  answ.line := normal(new_line(st[i1].center, st[i2].center), st[i1].center, st[i2].center);
end else begin
  answ.type_ := 0;
  d := distance(st[i1].center, st[i2].center);
  a := d*st[i1].r/(st[i1].r+st[i2].r);
  b := d*st[i2].r/(st[i1].r+st[i2].r);
  f1 := otn(st[i1].center, st[i2].center, a/(a+b));
  x := a*(b+a)/(b-a);
  f2 := otn(st[i2].center, st[i1].center, (x+a+b)/(a+b));
  answ.circle.center := middle(f1, f2);
  answ.circle.r := distance(f2, f1)/2; 
end;
result := answ;
end;
//
procedure cross_lines(l1, l2 : line);
begin
  answ1.x := (-l1.C*l2.B+l2.C*l1.B)/(l1.A*l2.B-l1.B*l2.A); answ1.y := (-l1.C*l2.A+l2.C*l1.A)/(l1.B*l2.A-l2.B*l1.A);
  answ2.x := answ1.x; answ2.y := answ1.y;
end;
//
Procedure PLProject(Const P : Point; Const L : Line; Var P1 : Point);
Var k : Real;
Begin
  With P,L Do
  Begin
    k:=(A*x+B*y+C)/(Sqr(A)+Sqr(B));
    P1.x:=x-A*k;
    P1.y:=y-B*k;
  End;
End;
//
Function Eq(Const a,b : Real) : Boolean;
Begin
  Eq:=Abs(a-b)<=Eps;
End;
//
procedure cross_line_circle (l : line; c : circle);
var p :point;
    xx, yy, d, t : extended;
    CPPoints : longint;
begin
  PLProject(C.center,L,P);
  //
  d:=distance(c.center, P); CPPoints:=0;
  If Eq(d,c.r) Then CPPoints:=1
  Else If d<c.r Then CPPoints:=2
  Else no_result:=true;
  //
  t:=Sqr(c.r)-Sqr(d);
  If t<0 Then t:=0 Else t:=Sqrt(t)/d;
  xx:=(P.x-c.center.x)*t; yy:=(P.y-c.center.y)*t;
  answ1.x:=P.x-yy; answ1.y:=P.y+xx;
  answ2.x:=P.x+yy; answ2.y:=P.y-xx;
end;
//
procedure cross_circles(c1, c2 : circle);
var d2, t, d, xx, yy: extended;
    p : point;
    CPPoints : longint;
begin
  d2 := distance(c1.center, c2.center)*distance(c1.center, c2.center);
  t:=(Sqr(C1.R)-Sqr(C2.R)+d2)/(2*d2);
  p := otn(c1.center, c2.center, t);
  //
  d:=distance(c1.center, P); CPPoints:=0;
  If Eq(d,c1.r) Then CPPoints:=1
  Else If d<c1.r Then CPPoints:=2
  Else no_result:=true;
  //
  t:=Sqr(c1.r)-Sqr(d);
  If t<0 Then t:=0 Else t:=Sqrt(t)/d;
  xx:=(P.x-c1.center.x)*t; yy:=(P.y-c1.center.y)*t;
  answ1.x:=P.x-yy; answ1.y:=P.y+xx;
  answ2.x:=P.x+yy; answ2.y:=P.y-xx;
end;
//
procedure cross_objects(o1, o2 : object_);
begin
  if (o1.type_ = 0) and (o2.type_ = 0) then cross_circles(o1.circle, o2.circle);
  if (o1.type_ = 0) and (o2.type_ = 1) then cross_line_circle(o2.line, o1.circle);
  if (o1.type_ = 1) and (o2.type_ = 0) then cross_line_circle(o1.line, o2.circle);
  if (o1.type_ = 1) and (o2.type_ = 1) then cross_lines(o1.line, o2.line);
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(st[1].center.x, st[1].center.y, st[1].r);
Readln(st[2].center.x, st[2].center.y, st[2].r);
Readln(st[3].center.x, st[3].center.y, st[3].r);
//
p1 := cross(1, 2);
p2 := cross(1, 3);
cross_objects(p1, p2);
//
answ := closer(answ1, answ2);
if (not no_result) then
  Writeln(answ.x:0:6, ' ', answ.y:0:6);
//
//close(input);
end.