var
  a,b,c : array[1..100000] of longint;
   n,m,x,y,i,j,kol : longint;



begin

  readln(n,m,x,y);
   for i:=1 to n do read(a[i]);
   readln;
  for i:=1 to m do read(b[i]);

  i:=1; j:=1; kol:=0;
   while (i<=n) do
    begin
     while (j<=m) and (b[j]<a[i]-x) do inc(j);
      if j>m
       then
        begin
         break;
        end
       else
        begin
         if b[j]<=a[i]+y
          then
         begin
          c[i]:=j;
           inc(kol);
          inc(j);
         end;
        end;
     inc(i);
    end;
   writeln(kol);
  for i:=1 to n do if c[i]<>0 then writeln(i,' ',c[i]);

end.