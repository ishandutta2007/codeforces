Var
    a: array[1..2,1..100] of longint;
     n,k,i: longint;
      answer: extended;


Begin

  readln(n,k);
   for i:=1 to n do readln(a[1,i],a[2,i]);

  answer:=0;
   for i:=1 to n-1 do
    answer:=answer + sqrt( sqr(a[1,i]-a[1,i+1]) + sqr(a[2,i]-a[2,i+1]));

  answer:=answer / 50 * k;
   writeln(answer:0:9);

End.