var a,ans : array[1..100] of longint;
    n,i,tek,kol : longint;
 begin

  readln(n);
   for i:=1 to n do read(a[i]);

  kol:=0; tek:=0;
   for i:=1 to n do
    if (a[i]=tek+1)
     then
      begin

        inc(kol);
         ans[kol]:=2000+i;
        inc(tek);

      end;

  writeln(kol);
   for i:=1 to kol do write(ans[i],' ');

 end.