program Project50A;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  k, M, N: Integer;

begin
  Readln(M, N);
  if (M mod 2 = 0) or (N mod 2 = 0) then
    k := (N * M) div 2
  else
    k := (M * N - 1) div 2;
  Writeln(k);
  readln;
  readln;
end.