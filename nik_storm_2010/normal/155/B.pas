var
  a : array[1..2,1..1000] of longint;
   n, kol, answer, i : longint;


procedure quicksort(l,r:longint);
var i,j,cur1,cur2,tek,tmp:longint;
 begin
  i:=l; j:=r; tek:=random(r-l+1)+l;
   cur1:=a[1,tek]; cur2:=a[2,tek];
    while i<=j do
     begin
      while (a[2,i]<cur2) or ((a[2,i]=cur2) and (a[1,i]<cur1)) do inc(i);
       while (a[2,j]>cur2) or ((a[2,j]=cur2) and (a[1,j]>cur1)) do dec(j);
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

  readln(n);
   for i:=1 to n do readln(a[1,i],a[2,i]);
  quicksort(1,n);

  answer:=0; kol:=1; i:=n;
   while (i<>0) and (kol<>0) do
    begin
     answer:=answer+a[1,i];
      inc(kol,a[2,i]-1);
     dec(i);
    end;
  writeln(answer);

end.