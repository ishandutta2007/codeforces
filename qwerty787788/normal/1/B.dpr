program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var n, i, x, y : longint;
    s, xs : string;
//
function only_numbers(s:string):boolean;
var answ : boolean;
    i : longint;
begin
answ := true;
for i := 1 to length(s) do
  if (not((s[i]>='0')and(s[i]<='9'))) then begin
    answ := false;
    break;
  end;
result := answ;
end;
//
function num2char(x : longint):string;
var answ : string;
begin
  answ := alph[((x-1) mod 26)+1];
  while (((x-1) div 26)<>0) do begin
    x := (x-1) div 26;
    answ := alph[((x-1) mod 26)+1]+answ;
  end;
  result := answ;
end;
//
function type_string(s:string):byte;// 1-R1C1; 2-A1
begin
if (s[1]<>'R') then result := 2 else
if (s[2]>='A') and (s[2]<='Z') then result := 2 else
if (only_numbers(copy(s, 2, length(s)))) then result := 2 else result := 1;
end;
//
function first_number(s:string):longint;
var i : longint;
begin
for i := 1 to length(s) do
  if (s[i]>='0') and (s[i]<='9') then begin
    result := i;
    break;
  end;
end;
//
function char2num(s:string):longint;
var summ, i, add : longint;
begin
summ := 0; add := 1;
for i := length(s) downto 1 do begin
  summ := summ + add*pos(s[i], alph);
  add := add*26;
end;
result := summ;
end;
//
begin
Readln(n);
for i := 1 to n do begin
  Readln(s);
  if (type_string(s) = 1) then begin
    y := StrToInt(copy(s, 2, pos('C', s)-2));
    x := StrToInt(copy(s, pos('C', s)+1, length(s)));
    Writeln(num2char(x),y);
  end else begin
    xs := copy(s, 1, first_number(s)-1);
    y := char2num(xs);
    x := StrToInt(copy(s, first_number(s), length(s)));
    Writeln('R', x, 'C', y);
  end;
end;
end.