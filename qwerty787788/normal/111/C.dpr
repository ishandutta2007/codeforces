program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type sit = record
  a: array[0..40] of boolean;
end;
//const alph = '23456789TJQKA';
var N, M : longint;
    i, max, count : longint;
    s : sit;
//
function toI(x, y : longint):longint;
begin
if (x<1) or (y<1) or (x>n) or (y>m) then toI := 0 else
toI := (y-1)*n+x;
end;
//
function toXY(i, x : longint): longint; //x=1 -> x, x=2 -> y
begin
  if (x=1) then toXY := ((i-1) mod n)+1 else
                toXY := ((i-1) div n)+1;
end;
//
function okey(i : longint; s :sit):boolean;
var x, y : longint;
begin
  x := toXY(i, 1);
  y := toXY(i, 2);
  if ((s.a[toI(x, y)]) or (s.a[toI(x-1, y)]) or (s.a[toI(x+1, y)]) or (s.a[toI(x, y-1)]) or (s.a[toI(x, y+1)])) then
    okey := true else okey := false;
end;
//
procedure x(s : sit);
var i : longint;
    ok : boolean;
    sum : longint;
begin
inc(count);
if (count > 3000000) then exit;
ok := true;
sum := 0;
  for i := 1 to n*m do
    if (s.a[i]= false) then inc(sum);
if (sum <= max) then exit;
for i := 1 to n*m do
  if (not okey(i, s)) then begin
    ok := false;
    if (toI(toXY(i, 1)+1, toXY(i, 2))<>0) then begin
      s.a[toI(toXY(i, 1)+1, toXY(i, 2))] := true;
      x(s);
      s.a[toI(toXY(i, 1)+1, toXY(i, 2))] := false;
    end;
    if (toI(toXY(i, 1), toXY(i, 2)+1)<>0) then begin
      s.a[toI(toXY(i, 1), toXY(i, 2)+1)] := true;
      x(s);
      s.a[toI(toXY(i, 1), toXY(i, 2)+1)] := false;
    end;
    if (toI(toXY(i, 1), toXY(i, 2))<>0) then begin
      s.a[toI(toXY(i, 1), toXY(i, 2))] := true;
      x(s);
      s.a[toI(toXY(i, 1), toXY(i, 2))] := false;
    end;
    if (toI(toXY(i, 1)-1, toXY(i, 2))<>0) then begin
      s.a[toI(toXY(i, 1)-1, toXY(i, 2))] := true;
      x(s);
      s.a[toI(toXY(i, 1)-1, toXY(i, 2))] := false;
    end;
    if (toI(toXY(i, 1), toXY(i, 2)-1)<>0) then begin
      s.a[toI(toXY(i, 1), toXY(i, 2)-1)] := true;
      x(s);
      s.a[toI(toXY(i, 1), toXY(i, 2)-1)] := false;
    end;

    break;
  end;
if (ok) then begin
  sum := 0;
  for i := 1 to n*m do
    if (s.a[i]= false) then inc(sum);
  if (sum > max) then
    max := sum;
end;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(n, m); max := 0; count := 0;
for i := 1 to n*m do
  s.a[i] := false;
x(s);
Writeln(max);
//
//close(input);
end.