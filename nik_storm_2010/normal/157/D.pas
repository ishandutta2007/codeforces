var
    a : array[1..3,1..100000] of longint;
     may : array[1..100000] of boolean;
    n,m,i,answer,kolminus,tek : longint;



begin

  readln(n,m); kolminus:=0;
   for i:=1 to n do
    begin
     readln(a[1,i]);
      if a[1,i]>0
       then
        begin
         inc(a[2,a[1,i]]);
        end
       else
        begin
         inc(a[3,abs(a[1,i])]);
         inc(kolminus);
        end;
    end;

  answer:=0;
   for i:=1 to n do
    begin
     tek:=a[2,i]+kolminus-a[3,i];
      if tek=m
       then
      begin
       inc(answer);
       may[i]:=true;
      end;
    end;

  for i:=1 to n do
   begin
    if a[1,i]>0
     then
      begin
       if may[a[1,i]]=false
        then
         begin
          writeln('Lie');
         end
        else
         begin
          if answer=1
           then
            begin
             writeln('Truth');
            end
           else
            begin
             writeln('Not defined');
            end;
         end;
      end
     else
      begin
       if may[abs(a[1,i])]=false
        then
         begin
          writeln('Truth');
         end
        else
         begin
          if answer=1
           then
            begin
             writeln('Lie');
            end
           else
            begin
             writeln('Not defined');
            end;
         end;
      end;

   end;

end.