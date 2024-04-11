program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type conv = record
  w, h, id, answ : longint;
end;
var a : array [0..5001] of conv;
    i, j, N, w, h, count, n_max, last : longint;
//
procedure sort(l, r : longint);
var i, j, m : longint;
begin
  i := l; j := r; m := a[(l+r) div 2].w;
  repeat
    while (a[i].w < m) do inc(i);
    while (a[j].w > m) do dec(j);
    if (i <= j ) then begin
      a[0] := a[i];
      a[i] := a[j];
      a[j] := a[0];
      inc(i);
      dec(j);
    end;
  until i > j;
  if (l < j) then sort(l, j);
  if (i < r) then sort(i, r);
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(N, w, h); count := 1;
a[1].w := w; a[1].h := h; a[1].id := 0;
for i := 1 to N do begin
  Readln(w, h);
  if (w > a[1].w) and (h > a[1].h) then begin
    inc(count);
    a[count].id := i;
    a[count].w := w;
    a[count].h := h; 
  end;
end;
//
sort(1, count);
//
for i := count downto 1 do begin
  n_max := 0;
  for j := i+1 to count do
    if (a[j].w > a[i].w) and (a[j].h > a[i].h) and (a[j].answ+1 > n_max) then n_max := a[j].answ+1;
  a[i].answ := n_max;
end;
//
Writeln(a[1].answ); last := 1;
for i := 2 to count do
  if (a[i].answ = a[last].answ - 1) and (a[i].w > a[last].w) and (a[i].h > a[last].h) then begin
    last := i;
    Write(a[i].id, ' ');
  end;
Writeln;
//
//close(input);
end.