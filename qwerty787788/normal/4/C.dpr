program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;
const const_p = 31;
      modul = 1000000;
var a : array [0..modul] of longint;
    b : array [1..100000] of string;
    next, sum : array [1..100000] of longint;
    N, i, j, aMax, nextMax : longint;
    h : int64;
    s : string;
    found : boolean;
    p_ : array [1..32] of int64;
//
function hash(s:string):int64;
var i : longint;
    answ: int64;
    x : byte;
    c : char;
begin
answ := 0;
for i := 1 to length(s) do begin
  c := s[i];
  x := ord(c)-ord('a')+1;
  answ := (answ + x*p_[i]) mod modul;
end;
hash := answ;
end;
//
procedure add(s:string);
var h, i, last : int64;
begin
  h := hash(s);
  if (a[h] = 0) then begin
    inc(nextMax);
    a[h] := nextMax;
    next[nextMax] := 0;
    b[nextMax] := s;
    Writeln('OK');
  end else begin
    i := a[h];
    while (b[i] <> s) and (i<>0) do begin
      last := i;
      i := next[i];
    end;
    if (i = 0) then begin
      inc(nextMax);
      next[last] := nextMax;
      b[nextMax] := s;
      Writeln('OK');
    end else begin
      inc(sum[i]);
      Writeln(s, sum[i]);
    end;
  end;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
p_[1] := 1;
for i := 2 to 32 do
   p_[i] := (p_[i-1]*const_p) mod modul;
//
Readln(n); aMax := 0; nextMax := 0;
for i := 1 to N do begin
  Readln(s);
  add(s);
end;
//
//close(input);
end.