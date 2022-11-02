Var
    a: array[1..1000] of char;
     n,i,j,humster,tiger,p,kol,answer: longint;


Begin

  humster:=0;
   tiger:=0;
    readln(n);
     for i:=1 to n do
      begin
       read(a[i]);
        if a[i]='H' then inc(humster)
                     else inc(tiger);
      end;

  answer:=MaxLongint;
  for i:=1 to n do
   begin
    j:=i;
     kol:=0;
      p:=0;
       while kol<>humster do
        begin
         if j = n+1 then j:=1;
          if a[j]='T' then inc(p);
         inc(j);
          inc(kol);
        end;
    if answer>p
     then answer:=p;
   end;
  writeln(answer);

End.