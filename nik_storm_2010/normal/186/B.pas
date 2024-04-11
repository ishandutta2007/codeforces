uses math;
 var
    a:array[1..1000] of extended; b:array[1..1000] of longint;
     tek1,tek2:extended; n,t1,t2,k,i,x,y:longint;


procedure quicksort(l,r:longint);
var i,j,d2,w2,nom:longint; d1,w1:extended;
 begin
  i:=l; j:=r;
   nom:=random(r-l+1)+l;
  d1:=a[nom]; d2:=b[nom];
  while i<=j do
   begin
    while (a[i]<d1) or ((a[i]=d1) and (b[i]>d2)) do inc(i);
     while (a[j]>d1) or ((a[j]=d1) and (b[j]<d2)) do dec(j);
    if i<=j
     then
      begin
       w1:=a[i]; a[i]:=a[j]; a[j]:=w1;
        w2:=b[i]; b[i]:=b[j]; b[j]:=w2;
       inc(i); dec(j);
      end;
   end;
   if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
 end;


begin

  readln(n,t1,t2,k);
   for i:=1 to n do
    begin
     readln(x,y);
      tek1:=(x*t1) * (1-k/100) + (y*t2);
      tek2:=(y*t1) * (1-k/100) + (x*t2);
     a[i]:=max(tek1,tek2); b[i]:=i;
    end;
   randomize;
  quicksort(1,n);

  for i:=n downto 1 do
  writeln(b[i],' ',a[i]:0:2);

end.