program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type star = record
  x, y, z : extended;
end;
var N, i, j :longint;
    a : array [1..101] of star;
    t1, t2, max1 : longint;
    max : extended;
    center : star;
    x, y, z, R_max, p : extended;
//
function dist(i, j : longint) : extended;
begin
dist := (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z);
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
REadln(N);
for i := 1 to N do
  Readln(a[i].x, a[i].y, a[i].z);
//
R_max := -1; t1 := 1; t2 := 1;
//
for i := 1 to N do
  for j := i to N do
      if (dist(i, j)>max) then begin
        max := dist(i, j);
      end;
//
x := (a[t1].x+a[t2].x)/2;
y := (a[t1].y+a[t2].y)/2;
z := (a[t1].z+a[t2].z)/2;
a[N+1].x := x;
a[N+1].y := y;
a[N+1].z := z;
//
p := 0.1;
for i := 1 to 50000 do begin
  max1 := 1;
  for j := 1 to N do
    if (dist(j, N+1) > dist(max1, N+1)) then max1 := j;
  x := a[max1].x;
  y := a[max1].y;
  z := a[max1].z;
  //
  a[n+1].x := a[n+1].x+(x-a[n+1].x)*p;
  a[n+1].y := a[n+1].y+(y-a[n+1].y)*p;
  a[n+1].z := a[n+1].z+(z-a[n+1].z)*p;
  p:=p*0.9995;
end;
//
Writeln(a[n+1].x:0:6, ' ', a[n+1].y:0:6, ' ', a[n+1].z:0:6);
//
//close(input);
end.