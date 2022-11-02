uses math;
var
 a,b:ansistring;
  kol4,kol7,answer,n,i,koef:longint;



begin

  readln(a);
   readln(b);
  n:=length(a);
   for i:=1 to n do
    if a[i]<>b[i]
     then
      begin
       if a[i]='4' then inc(kol4) else inc(kol7);
      end;
  koef:=min(kol4,kol7);
   answer:=answer+koef;
    kol4:=kol4-koef; kol7:=kol7-koef;
  answer:=answer+kol4+kol7;
  writeln(answer);

end.