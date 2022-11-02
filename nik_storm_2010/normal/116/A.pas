Program A116;
Var
  n,max,tek,i,a,b:longint;


Begin

  tek:=0;
   max:=-1000;
    readln(n);
     for i:=1 to n do
      begin
       readln(a,b);
        dec(tek,a);
         inc(tek,b);
          if tek>max then max:=tek;
      end;

  writeln(max);

End.