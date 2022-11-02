uses math;
var
    a1,a2,i,j,g,n,y : int64;



begin

  readln(n);
   g:=round(sqrt(n));
    a1:=high(int64);
   a2:=0;

  i:=1;
   while i<=g do
    begin

     if n mod i = 0 then
      begin

       j:=1;
        while j<=g do
         begin

          if n div i mod j = 0
           then
            begin

             y:=n div i div j;
              a1:=min(a1 ,(i+1)*(j+2)*(y + 2)-n);
               a1:=min(a1,(i+2)*(j+1)*(y+ 2)-n);
              a1:=min(a1,(i+2)*(j+2)*(y + 1)-n);

              a2:=max(a2,(i+1)*(j+2)*(y + 2)-n);
               a2:=max(a2,(i+2)*(j+1)*(y + 2)-n);
              a2:=max(a2,(i+2)*(j+2)*(y + 1)-n);

            end;
          inc(j);

         end;

      end;
     inc(i);

    end;

  writeln(a1,' ',a2);

end.