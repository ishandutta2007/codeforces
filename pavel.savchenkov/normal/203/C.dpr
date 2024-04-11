program TaskC;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type cl = record
        num, xi, yi : longint;
        s : int64;
      end;
      mas = array[1..100000] of cl;
var n, a, b,i,j : longint;
    d,sum : longint;
    ar : mas;

procedure qSort(var v : mas; l,r:longint);
var i,j:longint;
    w,q :cl;
begin
  i := l; j := r;
  q := v[l + random(r - l)];
  repeat
    while (v[i].s < q.s) do inc(i);
    while (q.s < v[j].s) do dec(j);
    if (i <= j) then
    begin
      w:=v[i]; v[i]:=v[j]; v[j]:=w;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then qSort(v,l,j);
  if (i < r) then qSort(v,i,r);
end;

begin
    randomize;
    readln(n,d);
    readln(a,b);
    for i:=1 to n do
    begin
        readln(ar[i].xi, ar[i].yi);
        ar[i].num:=i;
        ar[i].s:=a*ar[i].xi+b*ar[i].yi;
    end;

    qsort(ar,1,n);

    sum:=0; j:=0;
    for i:=1 to n do
        if sum+ar[i].s<=d then begin sum:=sum+ar[i].s; j:=i; end else break;

    writeln(j);
    for i:=1 to j do
       write(ar[i].num,' ');
end.