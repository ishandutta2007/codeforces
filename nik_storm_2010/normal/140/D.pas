var
  a : array[1..100] of longint;
   n, i, fine, tek, answer : longint;



procedure quicksort(l,r:longint);
var i,j,cur,tmp:longint;
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
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  randomize;
   readln(n);
  for i:=1 to n do read(a[i]);

  quicksort(1,n);
   tek:=710;
    for i:=1 to n do
     begin
      if a[i]<=tek
       then
        begin
         tek:=tek-a[i];
          inc(answer);
         if tek<360 then fine:=fine + (360-tek);
        end
       else
        begin
         break;
        end;
     end;
  writeln(answer,' ',fine);

end.