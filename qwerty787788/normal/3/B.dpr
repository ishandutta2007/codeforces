program Project2;

{$APPTYPE CONSOLE}
{$R-}

uses
  SysUtils;
type l = record
  type_ : byte;
  m, av, id : longint;
  buy : boolean;
end;
var i, j, n, v, summ, s1, e1 : longint;
  a : array [0..100000] of l;
//
procedure ExchangeItems(x, y : longint);
begin
a[0]:= a[x];
a[x] := a[y];
a[y] := a[0];
end;
//
procedure QuickSort(L, R: longint);
var I, J, P: longint;
begin
  repeat
    I := L;
    J := R;
    P := (L + R) shr 1;
    repeat
      while (a[I].av > a[P].av) do Inc(I);
      while (a[J].av < a[P].av) do Dec(J);
      if I <= J then
      begin
        ExchangeItems(I, J);
        if P = I then
          P := J
        else if P = J then
          P := I;
        Inc(I);
        Dec(J);
      end;
    until I > J;
    if L < J then QuickSort(L, J);
    L := I;
  until I >= R;
end;
//
begin
//assign(input, 'input.txt'); reset(input);
//
Readln(n, v);
for i := 1 to n do begin
  Readln(a[i].type_, a[i].m);
  a[i].av := a[i].m*(3-a[i].type_);
  a[i].id := i;
end;
//
QuickSort(1, n); i := 0; summ := 0; a[n+1].type_ := 1; a[n+1].m := 0;
while (v > 0) and (i<n) do begin
  inc(i);
  if (a[i].type_ <= v) then begin
    summ := summ + a[i].m;
    v := v - a[i].type_;
    a[i].buy := true;
  end;
end;
//
s1 := 0; e1 := v;
for i := n downto 1 do
  if ((a[i].type_ = 1) and (a[i].buy)) then begin
    inc(e1);
    inc(s1, a[i].m);
    if (e1 = 2) then break;
  end;
//
if (e1=2) then
for i := 1 to n do
  if ((a[i].type_ = 2) and (a[i].buy = false)) then begin
    if (a[i].m > s1) then begin
      summ := summ - s1 + a[i].m;
      a[i].buy := true;
      e1 := v;
      for j := n downto 1 do
        if ((a[j].type_ = 1) and (a[j].buy)) then begin
          inc(e1);
          a[j].buy := false;
          if (e1 = 2) then break;
        end;
    end;
    break;
  end;
//
Writeln(summ); s1 := 0;
for i := 1 to n do
  if (a[i].buy) then begin
    s1 := s1 + a[i].m;
    if (s1 = summ) then   Writeln(a[i].id) else
                          Write(a[i].id, ' ');
  end;
//
//close(input);
end.