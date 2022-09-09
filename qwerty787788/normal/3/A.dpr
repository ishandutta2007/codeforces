program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
const alph = 'abcdefgh';
var i : longint;
    s : string;
    x1, y1, x2, y2 : byte;

begin
//assign(input, 'input.txt'); reset(input);
readln(s);
x1 := pos(s[1], alph); y1 := StrToInt(s[2]);
readln(s);
x2 := pos(s[1], alph); y2 := StrToInt(s[2]);
//
Writeln(max(abs(x2-x1), abs(y2-y1)));
//
While (x1<>x2) or (y1<>y2) do begin
if (x1<x2) then begin Write('R'); inc(x1); end;
if (x1>x2) then begin Write('L'); dec(x1); end;
if (y1>y2) then begin Write('D'); dec(y1); end;
if (y1<y2) then begin Write('U'); inc(y1); end;
Writeln;
end;
//close(input);
end.