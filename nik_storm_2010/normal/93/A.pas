Var
    a,b,n,m: longint;
     ost1,ost2: longint;


Begin

  readln(n,m,a,b);
   ost1:=a mod m; if ost1=0 then ost1:=m;
    ost2:=b mod m; if ost2=0 then ost2:=m;

  if ((a=1) and (b=n)) or ((ost1=1) and (ost2=m)) or (b<=a-ost1+m) or ((a mod m=1) and (b=n)) or (m=1) then writeln(1) else
   if (ost2=m) or (b<=a-ost1+m*2) or (ost1=1) or (b=n) or (a mod m = (b+1) mod m)  then writeln(2) else writeln(3);

End.