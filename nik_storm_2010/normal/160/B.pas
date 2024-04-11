var
    a : array[1..1100] of char;
     b : array[1..1100] of char;
    i,j,n: longint; priz1 , priz2:boolean;
    tmp : char;



begin

  readln(n);
   for i:=1 to n do read(a[i]);
  for i:=1 to n do
   for j:=i+1 to n do
    if a[i] > a[j]
     then
    begin
     tmp:=a[i];
      a[i]:=a[j];
     a[j]:=tmp;
    end;

   for i:=1 to n do read(b[i]);
  for i:=1 to n do
   for j:=i+1 to n do
    if b[i] > b[j]
     then
    begin
     tmp:=b[i];
      b[i]:=b[j];
     b[j]:=tmp;
    end;

  priz1:=true; priz2:=true;
   for i:=1 to n do
    begin
     if not(a[i]<b[i]) then priz1:=false;
     if not(a[i]>b[i]) then priz2:=false;
    end;
  if (priz1=true) or (priz2=true) then writeln('YES') else writeln('NO');

end.