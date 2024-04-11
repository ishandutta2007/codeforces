program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
var a, b, c, d, e, f, x, y, z : int64;
    ok : boolean;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(a, b, c, d, e, f);
x := 1000000; y := 0; z := 0;
//
if (a=0) and (b<>0) then y := MaxInt;
if (x>a) and (b<>0) and (a<>0) then begin
    y := y+(b)*(x div a);
    x := x mod a;
end;
//
if (c=0) and (d<>0) then z := MaxInt;
if (y>c) and (c<>0) and (d<>0) then begin
    z := z+(d)*(y div c);
    y := y mod c;
end;
//
if (e=0) and (f<>0) then x := MaxInt;
if (z>e) and (e<>0) and (f<>0) then begin
    x := x+(f)*(z div e);
    z := z mod e;
end;
//
if (((x>1000000) or (z > 1000000)) and (d<>0) and (b<>0)) or ((c=0) and (d<>0)) then Writeln('Ron') else Writeln('Hermione');
//
//close(input);
end.