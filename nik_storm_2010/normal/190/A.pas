uses math;
 var
   n,m:longint;


begin

  readln(n,m);
   if (n=0) or (m=0)
    then
     begin
      if (n=0) and (m<>0) then begin writeln('Impossible'); halt; end;
      if (n<>0) and (m=0) then begin writeln(n,' ',n); halt; end;
     end;
  writeln(n+max(0,m-n),' ',max(0,n+m-1));

end.