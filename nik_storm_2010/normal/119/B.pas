Uses
    math;
Var
    a: array[1..100] of longint;
     used: array[1..100] of boolean;
      j,i,n,k,q,kol,c,ktek: longint;
       priz: boolean;
        mi,ma,tek: extended;


procedure qsort(l,r:longint);
var i,j,d,w:longint;
     z:boolean;
 begin
  i:=l;
   j:=r;
    d:=a[(i+j) div 2];
     while i<=j do
      begin
       while a[i]<d do inc(i);
        while a[j]>d do dec(j);
         if i<=j
          then
           begin
            w:=a[i]; a[i]:=a[j]; a[j]:=w;
             z:=used[i]; used[i]:=used[j]; used[j]:=z;
              inc(i); dec(j);
           end;
      end;
  if i<r then qsort(i,r);
   if l<j then qsort(l,j);
 end;


Begin

  readln(n,k);
   for i:=1 to n do read(a[i]);
    kol:=n div k;

  mi:=MaxLongint;
   ma:=-10; ktek:=0;
    readln(q);
     for i:=1 to q do
      begin
       tek:=0;
        priz:=true;
         for j:=1 to kol do
          begin
           read(c);
            if (used[c]=false) then priz:=false;
             used[c]:=true;
              tek:=tek+a[c];
          end;
       if priz = false then inc(ktek);
       tek:=tek / kol;
        if tek<mi then mi:=tek;
         if tek>ma then ma:=tek;
       readln;
      end;

  if ktek<>k
   then
    begin
  qsort(1,n);
   tek:=0; c:=0;
    for i:=n downto 1 do
     if (c=kol)
      then
       begin
        break;
       end
      else
       begin
        if (used[i]=false)
         then
          begin
           inc(c);
            tek:=tek+a[i];
          end;
       end;
  if (c=kol) and (tek/kol>ma)
   then ma:=tek/kol;

   tek:=0; c:=0;
    for i:=1 to n do
     if (c=kol)
      then
       begin
        break;
       end
      else
       begin
        if (used[i]=false)
         then
          begin
           inc(c);
            tek:=tek+a[i];
          end;
       end;
  if (c=kol) and (tek/kol<mi)
   then mi:=tek/kol;
  end;
  write(mi:0:9,' '); write(ma:0:9);

End.