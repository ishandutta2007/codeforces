var a : array[1..2,1..100] of longint;
     pred1,pred2,kol,tek,n,k,i : longint;


procedure quicksort(l,r:longint);
var i,j,tmp,cur1,cur2:longint;
 begin
  i:=l; j:=r;
   tmp:=random(r-l+1)+l;
  cur1:=a[1,tmp]; cur2:=a[2,tmp];

  while i<=j do
   begin
    while (a[1,i]>cur1) or ((a[1,i]=cur1) and (a[2,i]<cur2)) do inc(i);
     while (a[1,j]<cur1) or ((a[1,j]=cur1) and (a[2,j]>cur2)) do dec(j);
    if i<=j
     then
      begin
       tmp:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=tmp;
        tmp:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=tmp;
       inc(i); dec(j);
      end;
   end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  readln(n,k);
   for i:=1 to n do
    readln(a[1,i],a[2,i]);
   randomize;
  quicksort(1,n);

  tek:=0; pred1:=0; pred2:=0; kol:=0;
   for i:=1 to n+1 do
    if (a[1,i] = pred1) and (a[2,i] = pred2)
     then
      begin
       inc(kol);
      end
     else
      begin
       if (tek+1<=k) and (k<=tek+kol)
        then
         begin
          writeln(kol);
          halt;
         end;
       tek:=tek+kol;
        pred1:=a[1,i]; pred2:=a[2,i];
       kol:=1;
      end;

end.