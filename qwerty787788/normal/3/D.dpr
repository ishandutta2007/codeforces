program Project2;

{$APPTYPE CONSOLE}
{$R-}

uses
  SysUtils, Math;
type cost = record
  c1, c2 : longint;
end;
var i, j : longint;
    balance, summ, min, b_max : int64;
    a : array [1..50000] of cost;
    b : array [0..50000] of longint;
    s : string;
    no_result : boolean;
//
function bigger(a1, a2 : longint) : boolean;
begin
if (a[b[a1]].c1-a[b[a1]].c2 > a[b[a2]].c1-a[b[a2]].c2) then result := true else result := false;
end;
//
function value(n : longint):longint;
begin
result := a[b[n]].c1-a[b[n]].c2;
end;
//
procedure ExchangeItems(a1, a2 : longint);
var i : longint;
begin
i := b[a1];
b[a1] := b[a2];
b[a2] := i;
end;
//
procedure siftup(n : longint);
begin
while ((n <> 1) and (bigger(n div 2, n))) do begin
  ExchangeItems(n div 2, n);
  n := n div 2;
end;
end;
//
procedure push(n : longint);
begin
inc(b_max);
b[b_max] := n;
siftup(b_max);
end;
//
procedure siftdown(n : longint);
var j : longint;
begin
while (2*n<=b_max) and ((bigger(n, 2*n)) or (bigger(n, 2*n+1))) do begin
  if (value(2*n) < value(2*n+1)) then j := 2*n else j := 2*n+1;
  ExchangeItems(n, j);
  n := j;
end;
end;
//
function pop():longint;
var answ : longint;
begin
answ := b[1];
b[1] := b[b_max];
dec(b_max);
siftdown(1);
if (b_max < 0) then result := 0 else
result := answ;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(s);
balance := 0; summ := 0; b_max := 0;
for i := 1 to length(s) do begin
  if (s[i] = '(') then begin
    inc(balance);
    a[i].c1 := MaxInt; a[i].c2 := 0;
  end;
  if (s[i] = ')') then begin
    dec(balance);
    a[i].c1 := MaxInt; a[i].c2 := 0;
  end;
  if (s[i] = '?') then begin
    Readln(a[i].c1, a[i].c2);
    inc(summ, a[i].c2);
    s[i] := ')';
    dec(balance);
    push(i);
  end;
  if (balance < 0) then begin
      min := pop();
      if (min = 0) then no_result := true else begin
        inc(balance, 2);
        s[min] := '(';
        summ := summ + a[min].c1 - a[min].c2;
      end;
  end;
end;
//
if (no_result) or (balance <> 0) then Writeln('-1') else begin
  Writeln(summ);
  Writeln(s);
end;
//close(input);
end.