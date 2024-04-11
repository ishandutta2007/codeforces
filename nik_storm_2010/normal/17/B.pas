Uses
    math;
Var
    a: array[1..1000] of longint;
     g: array[1..1000,1..1000] of longint;
      k: array[1..1000,1..1000] of byte;
       n,m,i,x,y,z,mi,answer,ma,nom,j: longint;


Begin

  readln(n);
   for i:=1 to n do read(a[i]);
  readln;
   readln(m);
    for i:=1 to m do
     begin
      readln(x,y,z);
       if (g[x,y]>z) or (k[x,y]=0)
        then
         begin
          g[x,y]:=z;
           k[x,y]:=1;
         end;
     end;

  ma:=0;
   for i:=1 to n do
    if a[i] > ma
     then
      begin
       ma:=a[i];
        nom:=i;
      end;

  answer:=0;
  for i:=1 to n do
   if i<>nom
    then
     begin
      mi:=MaxLongint;
       for j:=1 to n do
        if (k[j,i]=1) and (g[j,i]<mi)
         then mi:=g[j,i];
      if mi = MaxLongint
       then
        begin
         writeln(-1);
          halt;
        end
       else
        begin
         answer:=answer+mi;
        end;
     end;
  writeln(answer);

End.