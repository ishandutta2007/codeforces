program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, k, p, x, ost : int64;
    i : longint;
//
function answ(n, k, x:int64):string;
begin
  if (2*k <= n) then begin
      if (x <= n - 2*k) then answ := '.' else
      begin if (x mod 2=0) then answ := 'X' else answ := '.' end;
    end else begin
      ost := 2*k -n;
      if (x >= n-ost) then answ := 'X' else
        if (x mod 2 = 0) then answ := 'X' else answ := '.';
    end
end;
//
begin
Readln(n, k, p);
for i := 1 to p do
  if (n mod 2 = 0) then begin //chetnoe
    Readln(x); Write(answ(n, k, x));
  end else
  begin
    Readln(x);
    if (k = 0) then Write('.') else
    if (k = 1) then begin
      if (x = n) then Write('X') else Write('.')
    end else begin
      if (x >= n-1) then Write('X') else Write(answ(n-1, k-1, x));
    end;
  end;
Writeln;
end.