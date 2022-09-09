program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type move = record
  id, add : longint;
end;
var i, j, n, max, a_max, value, ch : longint;
    s, s_name, answ : string;
    a : array [1..1001] of string;
    val, max_val : array [1..1001] of longint;
    change : array [1..1001] of longint;
    moves : array [1..1000] of move;
    win : array [1..1000] of longint;
//
begin
Readln(n);
for i := 1 to n do begin
  Readln(s);
  s_name := copy(s, 1, pos(' ', s)-1);
  value := StrToInt(copy(s, pos(' ', s)+1, length(s)));
  for j := 1 to a_max do
    if (a[j] = s_name) then break;
  if (j = 0) or (a[j]<>s_name) then begin
    inc(a_max); a[a_max] := s_name; val[a_max] := 0; j := a_max;
  end;
  val[j] := val[j]+value;
  moves[i].id := j; moves[i].add := value;
end;
//
max := -MaxInt;
for i := 1 to a_max do
  if (val[i] > max) then max := val[i];
 for i := 1 to a_max do
    if (val[i] = max) then win[i] := 1;
//
for i := 1 to a_max do
  val[i] := 0;
//
for i := 1 to n do begin
  inc(val[moves[i].id], moves[i].add);
  if (val[moves[i].id] >= max) and (win[moves[i].id]=1) then begin
    Writeln(a[moves[i].id]); break;
  end;
end;
end.