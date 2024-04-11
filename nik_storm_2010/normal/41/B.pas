var
    a: array[1..2000] of int64;
    ch1,ch2,n,answer,b: int64;
    i,j: longint;


Begin

  readln(n,b);
   for i:=1 to n do read(a[i]);

   answer:=b;
    for i:=1 to n do
     for j:=i+1 to n do
      if answer < ((b div a[i]) * a[j]) + (b mod a[i])
       then
        answer:=((b div a[i]) * a[j]) + (b mod a[i]);

  writeln(answer);

End.