program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var N, i : longint;
    answ, sum, t : int64;
    a : array [0..1000000] of longint;
    s : string;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(s); sum := 0; answ := 0; t := 0;
for i := 1 to length(s) do begin
  if (s[i]='(') then begin
    inc(t);
    if (a[t] = 0) then a[t] := i;
  end else begin
    if (t > 0) then 
    if ((i+1-a[t]) > answ) then begin
      answ := i+1-a[t];
      sum := 1;
    end else
    if ((i+1-a[t]) = answ) then inc(sum);
    a[t+1] := 0;
    dec(t);
  end;
  if (t<0) then t := 0;
end;
if (answ = 0) then sum := 1;
Writeln(answ, ' ', sum);
//
//close(input);
end.