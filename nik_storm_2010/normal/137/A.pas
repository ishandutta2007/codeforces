var
 leng,i,kol,answer : longint;
  s : string;
   tek : char;

begin

  readln(s); answer:=0;
   leng:=length(s);i:=1;
    while i<=leng do
     begin

       tek:=s[i]; kol:=0;
        while (i<=leng) and (s[i]=tek) do begin inc(i); inc(kol); end;
       if kol mod 5 = 0 then answer:=answer+kol div 5 else answer:=answer+1+kol div 5;

     end;
  writeln(answer);

end.