var
    s: array[1..1000] of ansistring;
    l: array[1..1000] of longint;
    i,j,y,max: longint;
    priz: string;


Begin

  i:=0;
   while not(eof) do
    begin
     inc(i);
      readln(s[i]);
       l[i]:=length(s[i]);
    end;

   max:=0;
    for j:=1 to i do
     if l[j]>max
      then max:=l[j];

   for j:=1 to max+2 do write('*');  writeln;

   priz:='left';
    for j:=1 to i do
     begin
       write('*');
       if (max-l[j]) mod 2 = 0
        then
         begin
          for y:=1 to (max-l[j]) div 2 do write(' ');
           write(s[j]);
            for y:=1 to (max-l[j]) div 2 do write(' ');
         end
        else
         begin
          if priz='left'
           then
            begin
             priz:='right';
              for i:=1 to (max-l[j]) div 2  do write(' ');
               write(s[j]);
                for y:=1 to (max-l[j]) div 2 + 1 do write(' ');
            end
           else
            begin
             priz:='left';
              for i:=1 to (max-l[j]) div 2 + 1 do write(' ');
               write(s[j]);
                for y:=1 to (max-l[j]) div 2 do write(' ');
            end;
         end;
       writeln('*');
     end;

  for j:=1 to max+2 do write('*');

End.