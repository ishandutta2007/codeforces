var
  x,y : array[1..200] of longint;
   n,i,j,kol1,kol2,kol3,kol4,answer : longint;



begin

  readln(n);
   for i:=1 to n do readln(x[i],y[i]);

  answer:=0;
   for i:=1 to n do
    begin
     kol1:=0; kol2:=0; kol3:=0; kol4:=0;
      for j:=1 to n do
       if i<>j
        then
         begin
          if (x[i]=x[j]) and (y[i]>y[j]) then inc(kol1);
           if (x[i]=x[j]) and (y[i]<y[j]) then inc(kol2);
           if (y[i]=y[j]) and (x[i]<x[j]) then inc(kol3);
          if (y[i]=y[j]) and (x[i]>x[j]) then inc(kol4);
         end;
     if (kol1>0) and (kol2>0) and (kol3>0) and (kol4>0) then inc(answer);
    end;
  writeln(answer);

end.