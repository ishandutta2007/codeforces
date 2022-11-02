Var
    a: array[1..100] of longint;
     n,i,answer,sum: longint;


Begin

  readln(n); sum:=0;
   for i:=1 to n do begin read(a[i]); sum:=sum+a[i]; end;

  answer:=0;
   for i:=1 to n do
    if ( sum-a[i] ) mod 2 = 0 then inc(answer);
  writeln(answer);

End.