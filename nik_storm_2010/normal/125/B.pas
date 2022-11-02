Const
    size = 1010;
Var
    s1: array[1..size] of char;
     s2: array[1..size] of longint;
      s3: array[1..size] of boolean;
       leng,i,step,j,start,nom: longint;
        s: ansistring;


Begin

  readln(s);
   leng:=length(s); step:=0; start:=0;
    for i:=1 to leng do
     if (ord(s[i])>=97) and (ord(s[i])<=122)
      then
       begin

         if (s[i-1]='<')
          then
           begin
            inc(start); s1[start]:=s[i]; s2[start]:=step; s3[start]:=false;
             for j:=1 to step do write('  ');
            writeln(s[i-1]+s[i]+s[i+1]);
             inc(step);
           end
          else
           begin
            for j:=start downto 1 do
             if (s1[j]=s[i]) and (s3[j]=false) then begin nom:=j; s3[j]:=true; break; end;
            for j:=1 to s2[nom] do write('  ');
             writeln(s[i-2]+s[i-1]+s[i]+s[i+1]);
              dec(step);
           end;

       end;

End.