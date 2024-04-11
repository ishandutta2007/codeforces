uses math;
var
 a : array[1..100000] of longint;
  b : array[1..100000] of longint;
   n,i,right,answer : longint;




procedure qsort(l,r:longint);
var i,j,d,w:longint;
 begin

   i:=l; j:=r;
    d:=a[random(r-l+1)+l];
     while i<=j do
      begin

       while a[i]<d do inc(i);
       while a[j]>d do dec(j);
        if  i<=j
         then
          begin

            w:=a[i]; a[i]:=a[j]; a[j]:=w;
            w:=b[i]; b[i]:=b[j]; b[j]:=w;
             inc(i); dec(j);

          end;

      end;
    if i<r then qsort(i,r);
   if l<j then qsort(l,j);

 end;




begin

  readln(n);
   for i:=1 to n do readln(a[i],b[i]);
  qsort(1,n);

  answer:=0; right:=0;
   for i:=1 to n do
    begin

      if b[i]<right then inc(answer);
      right:=max(right,b[i]);

    end;
  writeln(answer);

end.