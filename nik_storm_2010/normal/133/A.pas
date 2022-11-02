var
  s : string;
   d,i : longint;



begin

  readln(s);
   d:=length(s);
    for i:=1 to d do
     begin

       if (s[i]='H') or (s[i]='Q') or (s[i]='9')
        then
         begin

           writeln('YES');
            halt;

         end;

     end;
  writeln('NO');


end.