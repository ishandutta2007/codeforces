program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const alph = 'abcdefghijklmnopqrstuvwxyz';
var s, del : string;
    k, summ : longint;
    c : char;
    a : array [0..26] of longint;
    b : array [0..26] of char;
    i, j, min, start :longint;
//
begin
Readln(s); Readln(k);
for i := 1 to length(s) do
  inc(a[pos(copy(s, i, 1), alph)]);
for c := 'a' to 'z' do
  b[pos(c, alph)]:=c;
//
for i := 1 to 25 do begin
  min := i;
  for j := i+1 to 26 do
    if (a[j]<a[min]) then min := j;
  a[0] := a[i]; a[i] := a[min]; a[min] := a[0];
  b[0] := b[i]; b[i] := b[min]; b[min] := b[0];
end;
start := 1;
while (a[start] = 0) do inc(start);
summ := 0;
while (start < 27) and (a[start]+summ<=k) do  begin
    summ := summ + a[start];
    del := del + b[start];
    inc(start);
end;
Writeln(27-start);
for i := 1 to length(s) do
  if (pos(copy(s, i, 1), del)=0)
    then Write(s[i]); Writeln;
//
end.