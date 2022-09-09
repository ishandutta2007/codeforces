program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var N, answ, i, people : longint;
    s : string;
//
begin
//assign(input, 'input.txt'); reset(input);
//
answ := 0; people := 0;
while not eof do begin
  Readln(s);
  if (s[1]='+') then inc(people) else
  if (s[1]='-') then dec(people) else begin
    answ := answ + people*(length(s)-pos(':', s));
  end;
end;
Writeln(answ);
//
//close(input);
end.