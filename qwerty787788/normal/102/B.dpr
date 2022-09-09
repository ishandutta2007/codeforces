program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s:string;
    summ : longint;
//
procedure pr;
var i : longint;
    su : int64;
    new : string;
begin
su := 0;
for i := 1 to length(s) do
  su := su + StrToInt(copy(s, i, 1));
s := IntToStr(su);
end;
//
begin
Readln(s); summ := 0;
While (length(s)<>1) do begin
  pr;
  inc(summ);
end;
Writeln(summ);
end.