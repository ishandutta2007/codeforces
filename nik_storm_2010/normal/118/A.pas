var
    d,i: longint;
    s,sanswer: string;


Begin

  readln(s);
   d:=length(s);

   for i:=1 to d do
    if ord(s[i]) < 97
     then
      s[i]:=chr(ord(s[i])+32);

   i:=1;
    while i<=d do
     if (s[i]='a')or(s[i]='o')or(s[i]='y')or(s[i]='e')or(s[i]='u')or(s[i]='i')
      then
       begin
        delete(s,i,1);
         d:=length(s);
       end
      else
       begin
        inc(i);
       end;

   sanswer:='';
    for i:=1 to d do
     sanswer:=sanswer+'.'+s[i];

   writeln(sanswer);

End.