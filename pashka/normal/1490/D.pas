var
  a,d : array [1..100] of longint;
  t,n,i,j,k : longint;
procedure FindMax(x,y: longint);
var nom, max: longint;
begin
  max:=0;
  for var e:=x to y do
    if a[e]>max then begin
      max:=a[e];
      nom:=e;
    end;
  d[nom]:=k;
  inc(k);
  // x .. nom - 1
  if x <= nom - 1 then FindMax(x, nom - 1);
  // nom + 1 .. y
  if nom + 1 <= y then FindMax(nom + 1, y);
  dec(k);
end;
begin
  readln(t);
  for i:=1 to t do begin
    k:=0;
    readln(n);
    for j:=1 to n do read(a[j]);
    FindMax(1,n);
    for j:=1 to n do write(d[j],' ');
    writeln();
  end;
end.