program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const alph = '.X0';
var i, j, num_x, num_0 : longint;
    s : string;
    a : array [1..3, 1..3] of byte;
//
function win(player : byte):boolean;
var w : boolean;
    i, summ, j : byte;
begin
w:=false;
if ((a[1, 1] = player) and (a[2, 2] = player) and (a[3, 3] = player)) then w := true;
if ((a[3, 1] = player) and (a[2, 2] = player) and (a[1, 3] = player)) then w := true;
for j := 1 to 3 do begin
  summ := 0;
  for i := 1 to 3 do
    if (a[i, j] = player) then inc(summ);
  if (summ = 3) then w := true;
end;
for j := 1 to 3 do begin
  summ := 0;
  for i := 1 to 3 do
    if (a[j, i] = player) then inc(summ);
  if (summ = 3) then w := true;
end;
win := w;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
for j := 1 to 3 do begin
  Readln(s);
  for i := 1 to 3 do
    a[i, j] := pos(s[i], alph);
end;
for i := 1 to 3 do
  for j := 1 to 3 do begin
    if (a[i, j] = 2) then inc(num_x);
    if (a[i, j] = 3) then inc(num_0); 
  end;
//
if (not((num_x=num_0) or (num_x = num_0+1))) then Writeln('illegal') else begin
  if (win(2)) then begin
    if (num_x <> num_0+1) then Writeln('illegal') else writeln('the first player won');
  end else begin
    if (win(3)) then begin
      if (num_x <> num_0) then Writeln('illegal') else writeln('the second player won');
    end else begin
      if (num_x+num_0 = 9) then Writeln('draw') else
      if (num_x = num_0) then Writeln('first') else Writeln('second');
    end;
  end;
end;
//
//close(input);
end.