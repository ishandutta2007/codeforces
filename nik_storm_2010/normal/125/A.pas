Var
    n,a,b: longint;


Begin

  readln(n);
   b:=n div 3;
    if n mod 3 = 2 then inc(b);
   a:=b div 12;
    b:=b - (a*12);
   writeln(a,' ',b);

End.