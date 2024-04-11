Var
    a : array[1..100000] of longint;
     n,i,c,l,kol : longint;



procedure proverka(c,l:longint; var kol:longint);
var j,pred : longint;
 begin

  pred:=round(sqrt(c)); kol:=0;
   for j:=1 to pred do
    if (c mod j = 0)
     then
      begin

       if j*j = c
        then
         begin

          if (a[j]=0) or (i-a[j]>l) then inc(kol);
           a[j]:=i;

         end
        else
         begin

          if (a[c div j]=0) or (i-a[c div j]>l) then inc(kol);
           a[c div j]:=i;

          if (a[j]=0) or (i-a[j]>l) then inc(kol);
           a[j]:=i;

         end;

      end;

 end;



Begin

 readln(n);
  for i:=1 to n do
   begin

    readln(c,l);
     proverka(c,l,kol);
    writeln(kol);

   end;

End.