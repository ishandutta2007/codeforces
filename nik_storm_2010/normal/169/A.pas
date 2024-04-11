var a : array[1..2000] of longint;
     n,x,y,i : longint;


procedure quicksort(l,r:longint);
var i,j,cur,tmp:longint;
 begin
  i:=l; j:=r;
   cur:=a[random(r-l+1)+l];
  while i<=j do
   begin
    while a[i] < cur do inc(i);
     while a[j] > cur do dec(j);
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

  readln(n,x,y);
   for i:=1 to n do
    read(a[i]);
    randomize;
   quicksort(1,n);
  writeln(a[y+1]-a[y]);

end.