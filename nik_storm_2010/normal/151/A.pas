uses math;
var
  n,k,l,c,d,p,nl,np,kol1,kol2,kol3,answer : longint;




begin

  readln(n,k,l,c,d,p,nl,np);
   kol1:=k*l div nl;
    kol2:=c*d;
   kol3:=p div np;
  answer:=min(kol1,kol2); answer:=min(answer,kol3);
  writeln(answer div n);

end.