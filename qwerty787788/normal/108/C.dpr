program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type tr = record
  sp, d : longint;
end;
//const alph = '23456789TJQKA';
var N, p, i, j, x, y, z, t, d :longint;
    st : array[1..1000] of integer;
    a : array [1..1000] of tr;
    answ : extended;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(n, p);
for i := 1 to p do begin
  Readln(x, y, z);
  if (st[x] <> 2)  then st[x] := 1;
  st[y] := 2;
  a[x].sp := y; a[x].d := z;
end;
//
t := 0;
for i := 1 to n do
  if (st[i] = 1) then inc(t);
Writeln(T);
//
for i := 1 to N do
  if (st[i] = 1) then  begin
    j := i;
    d := MaxInt;
    Write(j, ' ');
    while (a[j].sp <> 0) do begin
      if (a[j].d < d) then d := a[j].d;
      j := a[j].sp;
    end;
    Writeln(j, ' ', d);
  end;
//
//close(input);
end.