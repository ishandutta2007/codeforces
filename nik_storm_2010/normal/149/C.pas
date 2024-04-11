var
   a,b : array[1..100000] of longint;
    first,second:array[0..100000] of longint;
     n,i,x,y,tek,pred : longint;  sum1,sum2:int64;



procedure quicksort(l,r:longint);
var i,j,tmp,cur:longint;
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
         tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
         tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;

         inc(i); dec(j);
        end;
     end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  randomize;
   readln(n);
    for i:=1 to n do
     begin
      read(a[i]);
      b[i]:=i;
     end;
  quicksort(1,n); sum1:=0;
   if n mod 2 = 1
    then
     begin
      second[0]:=1; sum2:=a[1];
       second[1]:=b[1];
      tek:=1;
     end else tek:=0;
  pred:=n div 2;
  for i:=pred downto 1 do
   if sum1>sum2
    then
     begin
      sum2:=sum2+a[tek+i*2];
       inc(second[0]);
      second[second[0]]:=b[tek+i*2];

      sum1:=sum1+a[tek+i*2-1];
       inc(first[0]);
      first[first[0]]:=b[tek+i*2-1];
     end
    else
     begin
      sum1:=sum1+a[tek+i*2];
       inc(first[0]);
      first[first[0]]:=b[tek+i*2];

      sum2:=sum2+a[tek+i*2-1];
       inc(second[0]);
      second[second[0]]:=b[tek+i*2-1];
     end;
     writeln(first[0]);
  for i:=1 to first[0] do write(first[i],' '); writeln;
  writeln(second[0]);
   for i:=1 to second[0] do write(second[i],' ');

end.