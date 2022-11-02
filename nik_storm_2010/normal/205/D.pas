var
    a,b:array[1..200001] of longint;
     n,x,y,i,leng,ans,tek,kol,sum:longint;


procedure quicksort(l,r:longint);
var i,j,nom,d1,d2,w:longint;
 begin
  i:=l; j:=r;
   nom:=random(r-l+1)+l;
  d1:=a[nom]; d2:=b[nom];
  while i<=j do
   begin
    while (a[i]<d1) or ((a[i]=d1) and (b[i]<d2)) do inc(i);
     while (a[j]>d1) or ((a[j]=d1) and (b[j]>d2)) do dec(j);
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

  readln(n); leng:=0;
   for i:=1 to n do
    begin
     readln(x,y);
      if x=y
       then
        begin
         inc(leng);
          a[leng]:=x;
         b[leng]:=0;
        end
       else
        begin
         a[leng+1]:=x; b[leng+1]:=0;
          a[leng+2]:=y; b[leng+2]:=1;
         inc(leng,2);
        end;
    end;
   randomize;
  quicksort(1,leng);

  i:=1; ans:=maxlongint;
   tek:=0; n:=(n+1) div 2;
    while i<=leng do
     if a[i]=tek
      then
       begin
        inc(kol); sum:=sum+b[i];
         if (kol>=n) and (sum<ans) then ans:=sum;
        inc(i);
       end
      else
       begin
        tek:=a[i]; kol:=1; sum:=b[i];
         if (kol>=n) and (sum<ans) then ans:=sum;
        inc(i);
       end;
  if ans<>maxlongint
    then writeln(ans)
  else writeln(-1);

end.