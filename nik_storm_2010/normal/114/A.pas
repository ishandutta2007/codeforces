Program A114;
Var
  k,st,l,kol:int64;


Begin

  readln(k,l); st:=1; kol:=-1;
   while st<=l do
    begin
     st:=st*k;
      inc(kol);
       if st=l
        then
         begin
          writeln('YES');
           writeln(kol);
          halt;
         end;
    end;

  writeln('NO');

End.