var
    a: array[1..100000] of longint;
    n,i: longint;


procedure qsort(l,r:longint);
var i,j,w,d:longint;
 begin
  i:=l;
   j:=r;
    d:=a[(i+j) div 2];
     while i<=j do
      begin
        while a[i]<d do inc(i);
        while a[j]>d do dec(j);
         if i<=j
          then
           begin
            w:=a[i];
             a[i]:=a[j];
              a[j]:=w;
               inc(i); dec(j);
           end;
      end;
   if i<r then qsort(i,r);
  if l<j then qsort(l,j);
 end;


Begin

  readln(n);
   for i:=1 to n do
    read(a[i]);

  qsort(1,n);
   for i:=1 to n-1 do
    if (a[i]<a[i+1]) and (a[i]*2>a[i+1]) and (a[i]<>1)
     then
      begin
       writeln('YES');
        halt;
      end;
  writeln('NO');

End.