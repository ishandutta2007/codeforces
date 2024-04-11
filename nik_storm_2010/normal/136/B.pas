uses math;
var
  x,y : array[1..100] of longint;
   answer : array[1..100] of longint;
    a,b,c,kol1,kol2,kolans : int64;
     i : longint;




begin

  readln(a,c);
   kol1:=0;
    while a<>0 do
     begin

       inc(kol1);
        x[kol1]:=a mod 3;
       a:=a div 3;

     end;

   kol2:=0;
    while c<>0 do
     begin

       inc(kol2);
        y[kol2]:=c mod 3;
       c:=c div 3;

     end;

   kolans:=max(kol1,kol2);
    for i:=1 to max(kol1,kol2) do
     begin

       if y[i]<x[i] then answer[i]:=(y[i]+3-x[i])
                     else answer[i]:=(y[i]-x[i]);

     end;

   c:=1; b:=0; i:=1;
    while i<=kolans do
     begin

       b:=b + (c*answer[i]);
        c:=c*3;
       inc(i);

     end;
  writeln(b);

end.