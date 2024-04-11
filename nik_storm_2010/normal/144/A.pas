var
 answer,min,nommin,max,nommax,i,c,n:longint;


begin

  readln(n);
   min:=MaxLongint; max:=0;
    for i:=1 to n do
     begin
      read(c);
       if c<=min then begin nommin:=i; min:=c; end;
      if c>max then begin nommax:=i; max:=c; end;
     end;
  answer:=0;
   if nommin<nommax then answer:=(nommax-1) + (n-nommin) - 1 else answer:=(nommax-1) + (n-nommin);
  writeln(answer);

end.