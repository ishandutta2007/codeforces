var
 a : array[1..100] of int64;
  n,i : longint; answer,j : int64;


begin

  readln(n);
   for i:=1 to n do read(a[i]);

   answer:=0; j:=1;
    while j<=n do
     begin
      answer:=answer+(a[j]-1)*j+1;
      inc(j);
     end;

  writeln(answer);

end.