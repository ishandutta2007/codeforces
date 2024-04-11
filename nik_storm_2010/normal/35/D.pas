var
 a:array[1..100] of longint;
  x,n,i,answer:longint;

procedure QuickSort(l,r:longint);
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
            inc(i);
           dec(j);
          end;
     end;
   if i<r then QuickSort(i,r);
  if l<j then QuickSort(l,j);
 end;


begin
 assign(input,'input.txt'); reset(input);
 assign(output,'output.txt') ; rewrite(output);
 readln(n,x);
  for i:=1 to n do
   begin
    read(a[i]);
    a[i]:=a[i]*(n-i+1);
   end;
 QuickSort(1,n);
  answer:=0; i:=1;
   while x>=a[i] do
    begin
     x:=x-a[i];
      inc(answer);
      inc(i);
     if i=n+1 then break;
    end;
  writeln(answer);
 close(input);
 close(output);
end.