var
    priz,n,i,d:longint; s1,s2,s:string; sim:char;


begin

  sim:=chr(39); readln(n);
  for i:=1 to n do
    begin
      readln(s); d:=length(s);
      if d<5 then priz:=-1 else
        begin
          s1:=copy(s,1,5); s2:=copy(s,d-4,5);
          if (s1='miao.') and (s2='lala.') then priz:=-1 else
          if (s1='miao.') then priz:=1 else
          if (s2='lala.') then priz:=0 else
          priz:=-1;
        end;
      if priz=1 then writeln('Rainbow'+sim+'s');
      if priz=0 then writeln('Freda'+sim+'s');
      if priz=-1 then writeln('OMG>.< I don'+sim+'t know!');
    end;

end.