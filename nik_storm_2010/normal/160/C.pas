var
    a : array[1..100000] of int64;
     n,kol,j,tek,i1,i2,k : int64; i : longint;


procedure quicksort(l,r:int64);
var i,j,tmp,cur:int64;
 begin
  i:=l; j:=r;
   cur:=a[random(r-l+1)+l];
    while i<=j do
     begin
      while a[i]<cur do inc(i);
       while a[j]>cur do dec(j);
      if i<=j
       then
        begin
         tmp:=a[i];
          a[i]:=a[j];
         a[j]:=tmp;

         inc(i); dec(j);
        end;
     end;
   if l<j then quicksort(l,j);
  if i<r then quicksort(i,r);
 end;


begin

  readln(n,k);
   for i:=1 to n do read(a[i]);
    randomize;
  quicksort(1,n);

  i:=1; tek:=1;
   while i<=n do
    begin
     j:=i; kol:=0;
      while (j<=n) and (a[i]=a[j]) do begin inc(j); inc(kol); end;
     if (tek<=k) and (k<=(j-1)*n)
      then
       begin
        k:=k-tek+1;
         if k mod kol = 0 then writeln(a[i],' ',a[k div kol])
         else writeln(a[i],' ',a[k div kol+1]);
        halt;
       end;
      tek:=(j-1)*n+1;
     i:=j;
    end;

end.