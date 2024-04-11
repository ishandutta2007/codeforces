Var
    a,b,c: array[1..100000] of longint;
     answer: array[1..100] of longint;
      n,m,k,i,j: longint;
       answer_sum: int64;


Begin

  readln(n,m,k);
   for i:=1 to m do readln(a[i],b[i],c[i]);
    for i:=1 to k do read(answer[i]);

  answer_sum:=0;
   for i:=1 to m do
    for j:=1 to k do
     if (answer[j]>=a[i]) and (answer[j]<=b[i])
      then answer_sum:=answer_sum + (abs(a[i]-answer[j])+c[i]);

  writeln(answer_sum);

End.