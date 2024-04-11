var
    n,m,l,r,i:longint;


begin

   readln(n,m); l:=0;
    while n<>0 do
     begin
      if l=0
       then
        begin
         if m mod 2 = 1
          then begin l:=m div 2+1; r:=m div 2+1; end
         else begin l:=m div 2; r:=m div 2+1; end;
        end;

      if n=1
       then
        begin
         writeln(l);
         dec(n);
        end
       else
        begin
         if l=r
          then
           begin
            writeln(l);
             dec(l); inc(r);
            dec(n);
           end
          else
           begin
            writeln(l); dec(l);
             writeln(r); inc(r);
            dec(n,2);
           end;
        end;
     end;

end.