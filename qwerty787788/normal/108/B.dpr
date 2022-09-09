program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
var N, i, j :longint;
    a : array[1..100000] of longint;
    br : boolean;
//
procedure qsort(l, r: longint); 
var 
i, j, x, y: longint; 
begin 
i := l; 
j := r; 
x := a[(l+r) div 2]; 
repeat 
while a[i] < x do inc(i); 
while a[j] > x do dec(j); 
if i <= j then 
begin 
y := a[i]; 
a[i] := a[j]; 
a[j] := y; 
inc(i); 
dec(j); 
end; 
until i > j; 
if l < j then qsort(l, j); 
if i < r then qsort(i, r); 
end; 
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(N);
for i := 1 to N do read(a[i]);
qsort(1, N);
//
br := false;
for i := 1 to N-1 do begin
  j := i+1;
  while (j <> N+1) and (a[j]<=a[i]) do inc(j);
  if (j <> N+1) then if (a[i]*2>a[j]) then br := true;
end;
//
if (br) then Writeln('YES') else Writeln('NO');
//
//close(input);
end.