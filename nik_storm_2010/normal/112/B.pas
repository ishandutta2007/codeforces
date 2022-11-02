Program B112;
Var
  n,x,y:longint;


procedure outputdata(s:string);
 begin
  writeln(s);
   halt;
 end;


Begin

  readln(n,x,y);
   if ((y=n div 2) and (x=n div 2))
    or ((y=n div 2) and (x=n div 2 + 1))
     or ((y=n div 2 + 1) and (x=n div 2))
      or ((y=n div 2 + 1) and (x=n div 2 +1))
       then outputdata('NO')
       else outputdata('YES');

End.