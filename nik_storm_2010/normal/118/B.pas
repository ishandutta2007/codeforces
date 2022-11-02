var
    n,i,j: longint;


Begin

  readln(n);

   i:=-1;
    while i<>n do
     begin
      inc(i);
       for j:=1 to (n-i)*2 do  write(' ');
        if i=0
         then
          write('0')
        else
         begin
          for j:=0 to i do write(j,' ');
           for j:=i-1 downto 1 do write(j,' ');
            if i<>0 then write('0');
         end;
      writeln;
     end;

    while i<>0 do
     begin
      dec(i);
        for j:=1 to (n-i)*2 do  write(' ');
         if i=0
          then
           write('0')
          else
           begin
            for j:=0 to i do write(j,' ');
             for j:=i-1 downto 1 do write(j,' ');
              if i<>0 then write('0');
           end;
      writeln;
     end;

End.