Program A20;
Var
  s : string;
  i,i1,d : longint;


BEGIN

  readln(s); s:=s+' ';
  d:=length(s); i:=1;
  while i<>d do
   if s[i]='/' then
                   begin
                    i1:=i;
                    while s[i1]='/' do inc(i1);
                    delete(s,i+1,i1-i-1);
                    d:=length(s);
                    inc(i);
                   end
               else inc(i);

  delete(s,length(s),1);
  if (s[length(s)]='/') and (length(s)<>1) then delete(s,length(s),1);
  writeln(s);

END.