program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
type answer = record
  x, y, z, time : extended;
end;
var N, i : longint;
    a : array [1..10001, 1..3] of Extended;
    vp, vs, px, py, pz, t_time, time : extended;
    answ : answer;
//
function dist2(x1, y1, z1, x2, y2, z2 : Extended): extended;
begin
dist2 := (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1);
end;
//
procedure find(t1, t2, x1, y1, z1, x2, y2, z2 : extended; k : longint);
begin
if (k > 1000) then begin
  answ.time := (t1+t2)/2;
  answ.x := (x1+x2)/2;
  answ.y := (y1+y2)/2;
  answ.z := (z1+z2)/2;
end else begin
  if ((t1+(t2-t1)/2)*vp < sqrt(dist2(x1+(x2-x1)/2, y1+(y2-y1)/2, z1+(z2-z1)/2, px, py, pz))) then
    find(t1+(t2-t1)/2, t2, x1+(x2-x1)/2, y1+(y2-y1)/2, z1+(z2-z1)/2, x2, y2, z2, k+1) else
    find(t1, t1+(t2-t1)/2, x1, y1, z1, x1+(x2-x1)/2, y1+(y2-y1)/2, z1+(z2-z1)/2, k+1)
end;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
answ.time := -1;
//
Readln(N);
for i := 1 to N+1 do
  Readln(a[i, 1], a[i, 2], a[i, 3]);
Readln(vp, vs);
REadln(px, py, pz);
//
t_time := 0; time := 0;
for i := 2 to N+1 do begin
  t_time := t_time+time;
  time := (sqrt(dist2(a[i, 1], a[i, 2], a[i, 3], a[i-1, 1], a[i-1, 2], a[i-1, 3]))/vs);
  if (sqrt(dist2(a[i, 1], a[i, 2], a[i, 3], px, py, pz))<=(t_time+time)*vp) then
    begin
    find(t_time, t_time+time, a[i-1, 1], a[i-1, 2], a[i-1, 3], a[i, 1], a[i, 2], a[i, 3], 0);
    break;
    end;
end;
//
if (answ.time = -1) then Writeln('NO') else begin
  Writeln('YES');
  Writeln(answ.time:0:8);
  Writeln(answ.x:0:8, ' ', answ.y:0:8, ' ', answ.z:0:8);
end;
//
//close(input);
end.