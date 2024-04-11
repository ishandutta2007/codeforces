program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, m, a, x, y : int64;
    answ : int64;
//
begin
Readln(n, m, a);
x := n div a; if (x*a<n) then inc(x);
y := m div a; if (y*a<m) then inc(y);
answ := x*y;
Writeln(answ);
end.