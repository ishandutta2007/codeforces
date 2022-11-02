uses math;
var
 x,y : array[1..3,1..500] of longint;
  a,b,c,i,j,n,m,answer,ans,P,kol,all : longint;



begin

  readln(n);
   for i:=1 to n do readln(x[1,i],x[2,i],x[3,i]);

  readln(m);
   for i:=1 to m do readln(y[1,i],y[2,i],y[3,i]);

  answer:=0;
   for i:=1 to n do
    begin

     all:=MaxLongint; P:=(x[1,i]*2) + (x[2,i]*2);
      for j:=1 to m do
       begin

        kol:=y[1,j] div x[3,i]; ans:=MaxLongint;
         if kol<>0
          then
           begin

            if (P mod (kol*y[2,j]) = 0) then ans:=(P div (kol*y[2,j])) * y[3,j]
                                         else ans:=(P div (kol*y[2,j])+1) * y[3,j];

           end;
        all:=min(all,ans);

       end;
     answer:=answer+all;

    end;
  writeln(answer);

end.