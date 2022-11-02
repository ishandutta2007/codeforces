var
    a,b,kol1,kol2,a1,b1,nok: int64;


Begin

  readln(a,b);

   a1:=a; b1:=b;
   while (a1<>0) and (b1<>0) do
    if a1>b1 then a1:=a1 mod b1
             else b1:=b1 mod a1;

   nok:=(a*b) div (a1+b1);

  kol1:=nok div a;
   kol2:=nok div b;

    if a < b then inc(kol2)
              else inc(kol1);

  if kol1=kol2 then writeln('Equal');
  if kol1>kol2 then writeln('Dasha');
  if kol1<kol2 then writeln('Masha');

End.