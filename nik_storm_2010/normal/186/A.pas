var
  s1,s2 : ansistring;  dif,i,l,x1,x2 : longint;


begin

  readln(s1); readln(s2);
   l:=length(s1);
  if l<>length(s2)
   then
    begin
     writeln('NO');
     halt;
    end;

  for i:=1 to l do
   if s1[i] <> s2[i]
    then
   begin
    inc(dif);
     if dif>2
      then
       begin
        writeln('NO');
        halt;
       end;
    x2:=x1; x1:=i;
   end;

  if (dif=1) or ((s1[x1]<>s2[x2]) or (s1[x2]<>s2[x1]))
   then writeln('NO')
  else writeln('YES');

end.