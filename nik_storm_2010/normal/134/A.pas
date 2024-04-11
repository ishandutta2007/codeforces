var
  a : array[1..200000] of longint;
   sum,n,i,answer : longint;




begin

  sum:=0;
   readln(n);
    for i:=1 to n do
     begin

      read(a[i]);
       sum:=sum+a[i];

     end;

   answer:=0;
    for i:=1 to n do
     if (sum-a[i]) / (n-1)  =  a[i]
      then
       begin

         inc(answer);
          a[i]:=-a[i];

       end;
   writeln(answer);
    for i:=1 to n do
     if a[i]<0 then write(i,' ');

end.