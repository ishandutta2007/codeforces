{ Author : Sazanovich Nikita }
{ Memory : 0.02 megabyte }
{ Time : length(S) }
var
 leng,i : longint;
  s,s1,s2 : ansistring;



begin

  readln(s);
   leng:=length(s); i:=1;
    while i<=leng do
     if s[i]=' '
      then
       begin
        while s[i+1]=' ' do
         begin
          delete(s,i+1,1);
           dec(leng);
         end;
        inc(i);
       end
      else
       begin
        if (s[i]='.') or (s[i]=',') or (s[i]='?') or (s[i]='!')
         then
          begin
           while s[i-1]=' ' do
            begin
             delete(s,i-1,1);
              dec(i);
             dec(leng);
            end;
           if s[i+1]<>' ' then
            begin
             s1:=copy(s,1,i);
              s2:=copy(s,i+1,leng-i);
              s:=s1+' '+s2;
             inc(leng);
            end;
           inc(i);
          end
         else
          inc(i);
       end;
  writeln(s);

end.