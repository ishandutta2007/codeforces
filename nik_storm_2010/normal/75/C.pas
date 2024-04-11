Uses
    math;
Var
    del: array[1..10000] of longint;
     a,b,n,i,koldel,low,high,t,k,maxx,m: longint;


Begin

  readln(a,b);
   m:=max(a,b);
    k:=round(sqrt(m));
     koldel:=0;
      for i:=1 to k do
       begin

        if (a mod i = 0) and (b mod i = 0)
         then
          begin
           inc(koldel);
            del[koldel]:=i;
          end;

        if (b mod (m div i)=0) and (a mod (m div i)=0)
         then
          begin
           inc(koldel);
            del[koldel]:=m div i;
          end;

       end;

  readln(n);
   for i:=1 to n do
    begin
     readln(low,high);
      maxx:=-1;
       for k:=1 to koldel do
        if (del[k]>=low) and (del[k]<=high) and (del[k]>maxx)
         then maxx:=del[k];
     writeln(maxx);
    end;

End.