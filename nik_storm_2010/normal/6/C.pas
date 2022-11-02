var
    a: array[1..100000] of longint;
    b: array[1..100000] of char;
    i,j,n,kol1,kol2: longint;


Begin

  readln(n);
   for i:=1 to n do read(a[i]);

   kol1:=0; kol2:=0;
    i:=1; j:=n;
     b[j]:='B'; b[i]:='A';
      while i-j<>1 do
       begin
        if (a[i]=0) and (b[i]='A')
         then
          begin
           inc(kol1);
            inc(i);
             if b[i] <> 'B' then
              begin
               dec(a[i]);
                b[i]:='A';
              end;
          end
         else
          begin
           if b[i]='A' then dec(a[i]);
          end;

         if (a[j]=0) and (b[j]='B')
          then
           begin
            inc(kol2);
             dec(j);
              if b[j] <> 'A' then
               begin
                dec(a[j]);
                 b[j]:='B';
               end;
           end
          else
           begin
            if b[j]='B' then dec(a[j]);
           end;

       end;

  writeln(kol1,' ',kol2);

End.