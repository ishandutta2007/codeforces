program storm;
var d,i:longint;
    s:string;

procedure inputdata;
begin
 readln(s);
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('YES')
           else writeln('NO');
end;

begin
 inputdata; d:=length(s); i:=d;
 while (s[i]=' ') or (s[i]='?') do dec(i);
 if (s[i]='A') or (s[i]='a') or (s[i]='E') or (s[i]='e') or (s[i]='I') or (s[i]='i')
   or (s[i]='O') or (s[i]='o') or (s[i]='U') or (s[i]='u') or (s[i]='Y') or (s[i]='y')
   then outputdata(1)
   else outputdata(0);
end.