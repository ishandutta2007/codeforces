program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
      alph2 = '#.ABCDEFGHIJKLMNOPQRSTUVWXYZ';
      alph3 = 'NESW';
type uch = record
  st, sp : longint;
end;
type point = record
  x, y : longint;
end;
type deyst = record
  st, len : longint;
end;
var N, M, i, j, j1, k, x, y, x_new, y_new, start, stop :longint;
    a : array [1..1000, 1..1000] of byte;
    b1_st, b1_sp, b2_st, b2_sp : array [1..1001] of longint;
    s1, s2 : array [1..1000000] of uch;
    de : array [1..100000] of deyst;
    toc : array [1..26] of point; 
    was, now : byte;
    c : char;
    ok : boolean;
    sol : boolean;
//
begin
sol := false;
//assign(input, 'input1000.txt'); reset(input);
//assign(output, 'output.txt'); rewrite(output);
//
REadln(N, M);
for i := 1 to N do begin
  for j := 1 to M do begin
    Read(c);
    a[i, j] := pos(c, alph2);
    if (pos(c, alph2)>2) then begin
      toc[pos(c, alph)].x := j;
      toc[pos(c, alph)].y := i;
    end;
  end;
  Readln;
  end;
//
fillchar(b1_st, sizeof(b1_st), -1);
fillchar(b1_sp, sizeof(b1_sp), -2);
fillchar(b2_st, sizeof(b2_st), -1);
fillchar(b2_sp, sizeof(b2_sp), -2);
//
j1 := 0; was := 1;
for i := 1 to N do begin
  for j := 1 to M do begin
    now := a[i, j];
    if (was = 1) and (now>1) then begin
      inc(j1);
      if (b1_st[i] = -1) then b1_st[i] := j1;
      b1_sp[i] := j1;
      s1[j1].st := j;
    end;
    if (was > 1) and (now = 1) then begin
      s1[j1].sp := j-1;
    end;
    was := now;
  end;
end;
//
j1 := 0; was := 1;
for i := 1 to M do begin
  for j := 1 to N do begin
    now := a[j, i];
    if (was = 1) and (now>1) then begin
      inc(j1);
      if (b2_st[i] = -1) then b2_st[i] := j1;
      b2_sp[i] := j1;
      s2[j1].st := j;
    end;
    if (was > 1) and (now = 1) then begin
      s2[j1].sp := j-1;
    end;
    was := now;
  end;
end;
//
Readln(k);
for i := 1 to K do begin
  Readln(c, j);
  de[i].st := pos(c, alph3);
  de[i].len := j;
end;
//
for i := 1 to 26 do
  if (toc[i].x <> 0) then begin
    ok := true;
    x := toc[i].x;
    y := toc[i].y;
    for j := 1 to K do begin
      if (de[j].st = 1) then begin
        x_new := x;
        y_new := y-de[j].len;
        ok := false;
        if (y_new > 1) then begin
          start := b2_st[x];
          stop := b2_sp[x];
          for j1 := start to stop do
            if (s2[j1].st <= y_new) and (s2[j1].sp >= y) then begin
              ok := true;
              break;
            end;
        end;
      end else
      if (de[j].st = 2) then begin
        x_new := x+de[j].len;
        y_new := y;
        ok := false;
        if (x_new < M) then begin
          start := b1_st[y];
          stop := b1_sp[y];
          ok := false;
          for j1 := start to stop do
            if (s1[j1].st <= x) and (s1[j1].sp >= x_new) then begin
              ok := true;
              break;
            end;
        end;
      end else
      if (de[j].st = 3) then begin
        x_new := x;
        y_new := y+de[j].len;
        ok := false;
        if (y_new < N) then begin
          start := b2_st[x];
          stop := b2_sp[x];
          ok := false;
          for j1 := start to stop do
            if (s2[j1].st <= y) and (s2[j1].sp >= y_new) then begin
              ok := true;
              break;
            end;
        end;
      end else
      if (de[j].st = 4) then begin
        x_new := x-de[j].len;
        y_new := y;
        ok := false;
        if (x_new > 1) then begin
          start := b1_st[y];
          stop := b1_sp[y];
          ok := false;
          for j1 := start to stop do
            if (s1[j1].st <= x_new) and (s1[j1].sp >= x) then begin
              ok := true;
              break;
            end;
        end;
      end;
      x := x_new;
      y := y_new;
      if (not ok) then break;
    end;
    if (ok) then begin Write(alph[i]); sol := true; end;
  end;
if (sol) then
  Writeln else Writeln('no solution');
//      c
//close(input);// close(output);
end.