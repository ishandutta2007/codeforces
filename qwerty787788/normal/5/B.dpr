program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var N, i, j, max_len : longint;
    a : array [1..1000] of string;
    l : boolean;
//
begin
//assign(input, 'input.txt'); reset(input);
//
N := 0; max_len := 0;
while not eof do begin
  inc(N);
  Readln(a[N]);
  if (length(a[N]) > max_len) then max_len := length(a[N]);
end;
//
l := false;
for i := 1 to max_len+2 do Write('*'); Writeln;
for i := 1 to N do begin
  Write('*');
  if ((max_len-length(a[i])) mod 2 = 0) then begin
    for j := 1 to (max_len-length(a[i])) div 2 do Write(' ');
    Write(a[i]);
    for j := 1 to (max_len-length(a[i])) div 2 do Write(' ');
  end else begin
    l := not(l);
    if (l) then for j := 1 to (max_len-length(a[i])) div 2 do Write(' ') else
                for j := 1 to ((max_len-length(a[i])) div 2)+1 do Write(' ');
    Write(a[i]);
    if (l) then for j := 1 to ((max_len-length(a[i])) div 2)+1 do Write(' ') else
                for j := 1 to ((max_len-length(a[i])) div 2) do Write(' ');
  end;
  Writeln('*');
end;
for i := 1 to max_len+2 do Write('*'); Writeln;
//
//close(input);
end.