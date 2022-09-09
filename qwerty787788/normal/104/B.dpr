program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, i : longint;
    answ, x : int64;

//
begin
Readln(n); answ := 0;
for i := 1 to n do begin
  read(x);
  answ := answ + 1 + (x-1)*(i);
end;
Writeln(answ);
end.