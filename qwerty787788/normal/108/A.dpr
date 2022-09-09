program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

//const alph = '23456789TJQKA';
var h, m :string;
    s : string;
//
function polyndrom:boolean;
begin
if (h[1] = m[2]) and (h[2] = m[1]) then result := true else result := false;
end;
//
procedure add;
var h1, m1 : integer;
begin
h1 := StrToInt(h);
m1 := StrToInt(m);
inc(m1);
if (m1>59) then begin
  m1 := 0;
  inc(h1);
end;
if (h1>23) then h1 := 0;
//
h := IntToStr(h1);
m := IntToStr(m1);
if length(h) = 1 then h := '0'+h;
if length(m) = 1 then m := '0'+m;
//
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(s);
h := copy(s, 1, pos(':', s)-1);
m := copy(s, pos(':', s)+1, length(s));
add;
while not polyndrom do add;
Writeln(h, ':', m);
//
//close(input);
end.