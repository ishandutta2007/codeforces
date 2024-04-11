Var
    leng,i,nom: longint;
     s: ansistring;


Begin

  readln(s);
   leng:=length(s);

  if (s[1]='@') or (s[leng]='@') then begin writeln('No solution'); halt; end;

  nom:=MaxLongint; i:=1;
   while i<=length(s) do
    begin
     if s[i] = '@'
      then
       begin
        s:=copy(s,1,i+1) + ',' + copy(s,i+2,length(s)-i-1);
         nom:=i+2;
       end;
     inc(i);
    end;
  if nom = MaxLongint then begin writeln('No solution'); halt; end;
  delete(s,nom,1);

  leng:=length(s);
   if s[leng] = ',' then begin writeln('No solutuion'); halt; end;
    for i:=1 to leng do
     if (s[i]=',') and ((s[i-1]=',') or (s[i-1]='@') or (s[i+1]=',') or (s[i+1]='@')) then begin writeln('No solution'); halt; end;
  writeln(s);

End.