program B79;
var
  nolife : array[0..1001] of longint;
  answer : array[1..1000] of string;
  n,m,k,t,x,y,i,j,kol,nom : longint;


procedure qsort(l,r:longint);
var i,j,d,w:longint;
 begin
  i:=l;
   j:=r;
    d:=nolife[(i+j) div 2];
     while i<=j do
      begin

       while nolife[i]<d do inc(i);
       while nolife[j]>d do dec(j);
        if i<=j then
         begin
          w:=nolife[i];
           nolife[i]:=nolife[j];
            nolife[j]:=w;
             inc(i);
              dec(j);
         end;

      end;

   if i<r then qsort(i,r);
   if l<j then qsort(l,j);
 end;


Begin

  readln(n,m,k,t);
   for i:=1 to k do
    begin
     readln(x,y);
     nolife[i]:=(x-1) * m + y;
    end;
     qsort(1,k);
      nolife[k+1]:=MaxLongint;

   for i:=1 to t do
    begin
     readln(x,y);
      kol:=(x-1) * m + y;
       for j:=0 to k do
        if (nolife[j]<=kol) and (nolife[j+1]>kol)
         then
          begin
           nom:=j;
            break;
          end;
      if kol = nolife[nom] then answer[i]:='Waste'else
       begin
        kol:=kol-nom;
         if kol mod 3 = 1 then answer[i]:='Carrots';
          if kol mod 3 = 2 then answer[i]:='Kiwis';
           if kol mod 3 = 0 then answer[i]:='Grapes';
       end;
    end;

  for i:=1 to t do
   writeln(answer[i]);

End.