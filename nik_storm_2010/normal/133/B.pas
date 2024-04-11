var
  s,tek : ansistring;
   answer,step : int64;
    i,leng : longint;




begin

  readln(tek);
   leng:=length(tek); s:='';
    for i:=1 to leng do
     begin

       if tek[i]='>' then s:=s+'1000';
        if tek[i]='<' then s:=s+'1001';
         if tek[i]='+' then s:=s+'1010';
          if tek[i]='-' then s:=s+'1011';
          if tek[i]='.' then s:=s+'1100';
         if tek[i]=',' then s:=s+'1101';
        if tek[i]='[' then s:=s+'1110';
       if tek[i]=']' then s:=s+'1111';

     end;

  leng:=length(s);
   answer:=0; step:=1;
    for i:=leng downto 1 do
     begin

       if s[i]='1' then answer:=(answer+step) mod 1000003;
        step:=step*2 mod 1000003;

     end;
  writeln(answer);

end.