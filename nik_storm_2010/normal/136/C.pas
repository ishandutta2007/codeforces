var
  a : array[1..100000] of longint;
   n,i : longint;




procedure qsort(l,r:longint);
var i,j,w,d:longint;
 begin

   i:=l; j:=r;
    d:=a[random(r-l+1)+l];
     while i<=j do
      begin

        while a[i]<d do inc(i);
         while a[j]>d do dec(j);
          if i<=j
           then
            begin

              w:=a[i]; a[i]:=a[j]; a[j]:=w;
               inc(i); dec(j);

            end;

      end;
    if i<r then qsort(i,r);
   if l<j then qsort(l,j);

 end;



begin

  readln(n);
   for i:=1 to n do read(a[i]);

  qsort(1,n);
  if a[n]=1
   then
    begin

      for i:=1 to n-1 do write(1,' ');
       write(2,' ');

    end
   else
    begin

      write(1,' ');
       for i:=1 to n-1 do write(a[i],' ');

    end;

end.