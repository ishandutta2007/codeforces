var
  a: array [1..10000] of longint;
  i, n,y,p: longint;
  b: array [1..200000] of longint;

begin
  readln(n);
  for i := 1 to n do
  readln(a[i]);
  for i:=1 to n do begin
  p:=0;
    if a[i] mod 4>0 then begin
  writeln('NO');
  p:=1;
  end;
  for y:=1 to a[i] do begin
  b[1]:=2;
  if (y<=a[i] div 2) and (y mod 2=0) then
  b[y]:=b[y-1]+2;
   if (y<=a[i] div 2) and (y mod 2=1) and (y>1) then
  b[y]:=b[y-1]+4; 
    if (y>a[i] div 2) and (y mod 2=0) then
  b[y]:=b[y-1]+4;
    if (y>a[i] div 2) and (y mod 2=1) then
  b[y]:=b[y-1]+2;
      if (y=a[i] div 2+1)  then
  b[a[i] div 2+1]:=1;
  end;
  if p=0 then
      writeln('YES');
  for y:=1 to a[i]-1 do begin
  if p=0 then begin
  write(b[y],' ');
  end;
  end;
    if p=0 then
  writeln(b[a[i]]);
  end;
end.