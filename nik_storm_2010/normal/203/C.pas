var
   a,b,ans:array[1..100000] of longint;
    n,d,i,answer,c,r,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d,w:longint;
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
        w:=b[i]; b[i]:=b[j]; b[j]:=w;
       inc(i); dec(j);
      end;
   end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  readln(n,d); readln(c,r);
   for i:=1 to n do
    begin
     readln(x,y);
      a[i]:=x*c+y*r;
     b[i]:=i;
    end;
   randomize;
  quicksort(1,n);

  answer:=0; i:=1;
   while true do
    begin
     if a[i]<=d
      then
       begin
        d:=d-a[i];
         inc(answer);
        ans[answer]:=b[i];
       end
      else break;
     inc(i); if i>n then break;
    end;
  writeln(answer);
   for i:=1 to answer do
  write(ans[i],' ');

end.