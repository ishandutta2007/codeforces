program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
var N, m, h, i :longint;
    sum : int64;
    a : array[1..1000] of longint;
    answ : extended;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(N, m, h);
dec(n);
for i := 1 to m do read(a[i]);
dec(a[h]); sum := 0;
for i := 1 to m do inc(sum, a[i]);
//
answ := 1;
if (N <= sum) then
for i := 1 to N do
  answ := answ * (sum-i+1-a[h])/(sum-i+1);
answ := 1-answ;
if (N > sum) then answ := -1;
//
Writeln(answ:0:7);
//
//close(input);
end.