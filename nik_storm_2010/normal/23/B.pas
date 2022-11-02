Var
    t,n,i: longint;


Begin

  readln(t);
   for i:=1 to t do
    begin
     readln(n);
      if n>2
       then writeln(n-2)
        else writeln(0);
    end;

End.