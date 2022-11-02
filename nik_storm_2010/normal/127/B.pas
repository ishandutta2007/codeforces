Var
    a: array[1..100] of longint;
     c,answer,n,i: longint;



Begin

  readln(n);
   for i:=1 to n do
    begin
     read(c);
      inc(a[c]);
    end;

  answer:=0;
   for i:=1 to 100 do answer:=answer+(a[i] div 2);
  writeln(answer div 2);

End.