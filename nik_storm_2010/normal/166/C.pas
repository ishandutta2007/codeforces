var a : array[1..500] of longint;
     coef,left,right,n,i,x,kol,tek : longint;


procedure quicksort(l,r:longint);
var i,j,tmp,cur:longint;
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


procedure findleng;
var i:longint;
 begin
  kol:=0; left:=0; right:=0;
   for i:=1 to n do
    if a[i] = x
     then
    begin
     if left = 0 then left:=i;
      inc(kol);
     right:=i;
    end;
 end;



begin

  readln(n,x);
   for i:=1 to n do
    read(a[i]);
    inc(n); a[n]:=x;
   randomize;
  quicksort(1,n);

  findleng;
   if kol = 1
    then
     begin
      coef:=1;
     end
    else
     begin
      dec(right);
      coef:=0;
     end;
    dec(n);

  for i:=0 to n do
   begin
    tek:=(n+i+coef+1) div 2;
     if (left<=tek) and (tek<=right+i)
      then
     begin
      writeln(i+coef);
      exit;
     end;
   end;

end.