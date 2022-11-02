var
    n,i,x: longint;

Begin

  readln(x);
   i:=0;
    n:=0;

     while (n<(abs(x))) or (odd(n)<>(odd(x))) do
      begin
       i:=i+1;
       n:=n+i;
      end;

  writeln(i);

End.