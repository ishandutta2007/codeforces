program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var N, i : longint;
    answ, a, v, d, l, w, t, v1, t1, l1, t1_1, t1_2 : extended;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(a, v);
Readln(l, d, w);
//
if (v <= w) then begin
  if (2*l*a <= v*v) then answ := sqrt(2*l/a) else answ := l/v+v/a/2;
end else begin
  // first
  t := sqrt(2*d/a);
  if (a*t <= w) then begin
    t1 := t;
    w := a*t;
  end else begin
    t1_1 := w/a;
    l1 := d-t1_1*t1_1*a/2;
    if (v-w)*(v+w)>=(l1)*a then begin
      t1 := t1_1+2*((-w+sqrt(w*w+a*l1))/a);
    end else begin
      t1_2 := (v-w)/a;
      l1 := l1-t1_2*(v+w);
      t1 := t1_1+t1_2*2+l1/v;
    end;
  end;
  // second
  if ((v+w)/2*(v-w)/a >= l-d) then begin
    answ := t1 + (-w+sqrt(w*w+2*(l-d)*a))/a;
  end else begin
    t1_1 := (v-w)/a;
    l1 := l-d-(v+w)*t1_1/2;
    answ := t1 + t1_1+l1/v;
  end;
end;
//
Writeln(answ:0:5);
//
//close(input);
end.