Var
    n,a,b,i,answer: longint;


Begin

  readln(n,a,b);
   for i:=1 to n do
    if (i-1>=a) and (n-i<=b) then inc(answer);
  writeln(answer);

End.