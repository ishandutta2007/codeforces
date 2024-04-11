uses math;
 var
  a,b,answer,kol1,kol2 : longint;
   i,j : longint;



begin

  readln(a,b); answer:=0;
   if (a=1) or (b=1)
    then
     begin

      writeln( max(a,b) );

     end
    else
     if (a=2) or (b=2)
      then
       begin

        answer:=(max(a,b) div 4) * 4;
         if max(a,b) mod 4 = 1 then answer:=answer + 2;
          if max(a,b) mod 4 > 1 then answer:=answer + 4;
         writeln(answer);

       end
      else
       begin

        kol1:=0; kol2:=0;
         for i:=1 to a do
          for j:=1 to b do
           if (i+j) mod 2 = 0 then inc(kol1) else inc(kol2);

        writeln( max(kol1,kol2) );

       end;

end.