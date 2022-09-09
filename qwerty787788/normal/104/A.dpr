program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, answ : longint;

//
begin
Readln(n);
n := n - 10; answ := 0;
if (n <= 0) then answ := 0 else
if ((n>=1) and (n<10)) or (n=11) then answ := 4 else
if (n=10) then answ := 15;
Writeln(answ);
end.