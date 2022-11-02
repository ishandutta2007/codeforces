var
    a: array[1..100000] of longint;
    i,n,answer: longint;
    sum,sumtek: int64;


Begin

  sum:=0;
   readln(n);
    for i:=1 to n do
     begin
      read(a[i]);
       sum:=sum+a[i];
     end;

  answer:=0;
   sumtek:=0;
    for i:=1 to n-1 do
     begin
      sumtek:=sumtek + a[i];
       sum:=sum - a[i];
        if sum = sumtek
         then inc(answer);
     end;

  writeln(answer);

End.