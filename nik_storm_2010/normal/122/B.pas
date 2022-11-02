Var
    leng,kol_four,kol_seven,i: longint;
     s: string;


Begin

  readln(s);
   kol_four:=0;
    kol_seven:=0;
     leng:=length(s);
      for i:=1 to leng do
       begin
        if s[i] = '4' then inc(kol_four);
        if s[i] = '7' then inc(kol_seven);
       end;

  if (kol_seven=0) and (kol_four=0)
   then
    writeln('-1')
   else
    if kol_four < kol_seven then writeln('7') else writeln('4');

End.