var n,i,min,kol,c,nom:longint;


begin

  readln(n); min:=maxlongint;
   for i:=1 to n do
    begin
     read(c);
      if c<min
       then
        begin
         min:=c; kol:=1; nom:=i;
        end
       else
        begin
         if c=min then inc(kol);
        end;
    end;

  if kol=1
   then
    begin
     writeln(nom);
    end
   else
    begin
     writeln('Still Rozdil');
    end;

end.