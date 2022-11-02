Program B106;
Var
  a,b,c,d : array[1..100] of longint;
  bol : array[1..100] of boolean;
  n,i,j,min,nom : longint;



BEGIN

  readln(n);
  for i:=1 to n do readln(a[i],b[i],c[i],d[i]);

  for i:=1 to n do
   for j:=1 to n do
    if (a[j]<a[i]) and (b[j]<b[i]) and (c[j]<c[i]) then bol[j]:=true;

  min:=1000000; nom:=0;

  for i:=1 to n do
   if (bol[i]=false) and (d[i]<min) then
          begin
           min:=d[i];
           nom:=i;
          end;

  writeln(nom);

END.