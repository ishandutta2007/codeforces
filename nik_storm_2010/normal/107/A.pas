uses
    math;
var
    intt: array[1..2,1..1000] of longint;
    outt: array[1..2,1..1000] of longint;
    answ: array[1..3,1..1000] of longint;
    n,i,p,a,b,d,tekmin,kol,j: longint;


Begin

  readln(n,p);
   for i:=1 to p do
    begin
     readln(a,b,d);
      intt[1,b]:=a;
       intt[2,b]:=d;
        outt[1,a]:=b;
         outt[2,a]:=d;
    end;

  kol:=0;
   for i:=1 to n do
    if (outt[1,i]<>0) and (intt[1,i]=0)
     then
      begin
       j:=i;
        tekmin:=outt[2,i];
         while outt[1,j]<>0 do
          begin
           tekmin:=min(tekmin,outt[2,j]);
            j:=outt[1,j];
          end;
          inc(kol);
         answ[1,kol]:=i;
        answ[2,kol]:=j;
       answ[3,kol]:=tekmin;
      end;
  writeln(kol);
   for i:=1 to kol do
    writeln(answ[1,i],' ',answ[2,i],' ',answ[3,i]);

End.