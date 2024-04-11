var
  a : array[1..100000] of longint;
   answer,tek,i,j : int64;
    s,n : longint;


begin

  readln(n);
   for s:=1 to n do read(a[s]);

  answer:=0; i:=1;
   while i<=n do
    begin
     j:=i;
      while (j<=n) and (a[j]=a[i]) do inc(j);
       tek:=(1+j-i) * (j-i) div 2;
      answer:=answer+tek;
     i:=j;
    end;
  writeln(answer);

end.