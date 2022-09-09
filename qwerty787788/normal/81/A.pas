program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a : array [0..200000] of char;
    leng, i : longint;
    last, c : char;
//
begin
//assign(input, 'input.txt'); reset(input);
//
last := '_'; a[0] := '_'; c := 'a'; i := 1;
while (c in ['a'..'z']) do begin
  read(c);
  if (c=last) then begin
    dec(leng);
    last := a[leng];
  end else begin
    inc(leng);
    a[leng] := c;
    last := a[leng];
  end;
end;
//
for i := 1 to leng do Write(a[i]); Writeln;
//
//close(input);
end.