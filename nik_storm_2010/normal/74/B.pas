var
    n,m,k,i: longint;
    s: shortstring;
    c: char;



Begin

  readln(n,m,k);
   readln(s);
    i:=0;
     while not eoln do
      begin

        inc(i);
         read(c);
          if c = '0'
           then
            begin

              if s = 'to head'
               then
                begin
                 if (m>k) and (m<>n) then inc(m);
                  if (m<k) and (m<>1) then dec(m);
                   dec(k);
                end
               else
                begin
                 if (m>k) and (m<>n) then inc(m);
                  if (m<k) and (m<>1) then dec(m);
                   inc(k);
                end;

            end
           else
            begin

              if s = 'to head'
               then
                begin
                 dec(k);
                  m:=n;
                end
               else
                begin
                 inc(k);
                  m:=1;
                end;

            end;

      if k = 1 then s:='to tail';
       if k = n then s:='to head';

        if m=k
         then
          begin
           writeln('Controller ',i);
            halt;
           end;

    end;

  writeln('Stowaway');

End.