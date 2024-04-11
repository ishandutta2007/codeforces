Const
    a: array[1..6,1..4] of string = (('000','010','011','001'),('000','010','100','110'),('010','011','110','111'),('000','001','100','101'),('001','011','101','111'),('100','110','111','101'));
Var
    i,j,kol: longint;
     c1,c2,c3,space: char;
      s1,s2: string;


Begin

  readln(c1,space,c2,space,c3); s1:=c1+c2+c3;
   readln(c1,space,c2,space,c3); s2:=c1+c2+c3;

  for i:=1 to 6 do
   begin

     kol:=0;
      for j:=1 to 4 do
       begin

         if a[i,j] = s1 then inc(kol);
          if a[i,j] = s2 then inc(kol);

       end;
     if kol = 2 then begin writeln('YES'); exit; end;

   end;
  writeln('NO');

End.