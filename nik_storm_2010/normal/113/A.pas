var
    part: array[1..500000] of shortstring;
    kind: array[1..500000] of shortstring;
    s,s1: ansistring;
    d,i,kol,d1,i1: longint;


procedure output(s:shortstring);
 begin
  writeln(s);
   halt;
 end;


procedure ins(p,k:shortstring);
 begin
  part[kol]:=p;
   kind[kol]:=k;
 end;


Begin

  readln(s);
   s:=s+' ';
    d:=length(s);
     i1:=1; i:=1;
      kol:=0;
       while i<=d do
        if s[i] = ' '
         then
          begin

            s1:=copy(s,i1,i-i1);
             i1:=i+1;
              inc(i);
               inc(kol);
                d1:=length(s1);

            if (d1>=4)and(copy(s1,d1-3,4)='lios') then ins('P','M') else
             if (d1>=5)and(copy(s1,d1-4,5)='liala') then ins('P','G') else
              if (d1>=3)and(copy(s1,d1-2,3)='etr') then ins('S','M') else
               if (d1>=4)and(copy(s1,d1-3,4)='etra')then ins('S','G') else
                if (d1>=6)and(copy(s1,d1-5,6)='initis')then ins('T','M') else
                 if (d1>=6)and(copy(s1,d1-5,6)='inites')then ins('T','G') else
                  begin
                   output('NO');
                    halt;
                  end;

          end
         else
          inc(i);
  if kol=1 then output('YES');
   for i:=1 to kol do
    if kind[i] <> kind[1]
     then output('NO');
  i:=1;
   while (i<=kol) and (part[i]='P') do inc(i);
    if part[i]<>'S' then output('NO');
     inc(i);
      while (i<=kol) and (part[i]='T') do inc(i);
       if i=kol+1
        then output('YES')
         else output('NO');

End.