Uses
    math;
Var
    a,b,m,i,miin: longint;
     s,s1: string;
      ch: int64;



Begin

  readln(a,b,m);
   miin:=min(a,m);
    for i:=1 to miin do
     begin
      ch:=i;
       ch:=ch*1000000000;
        if (m-(ch mod m)) mod m > b
         then
          begin
           s:='';
            ch:=i;
             while ch<>0 do
              begin
               str(ch mod 10,s1);
                ch:=ch div 10;
                 s:=s1+s;
              end;
           while length(s) <> 9 do s:='0'+s;
            s:='1 '+s;
             writeln(s);
              halt;
          end;
     end;
  writeln(2);

End.