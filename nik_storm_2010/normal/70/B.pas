uses
    math;
var
    s: array[1..50000] of longint;
    n,leng,kol,answer,i,d,k: longint;
    st : ansistring;
    c: char;


Begin

  readln(n);
   readln(st);
    d:=length(st);
     leng:=0;
      kol:=0;
       i:=1;
        while i<=d  do
         begin

          c:=st[i];
           if (c=' ') and ((st[i-1]='.') or (st[i-1]='!') or (st[i-1]='?'))
            then
             begin
              inc(kol);
               s[kol]:=leng;
                leng:=0;
             end
            else
             begin
              inc(leng);
             end;
           inc(i);

         end;
        inc(kol);
       s[kol]:=leng;

  i:=1;
   answer:=0;
    k:=0;
     leng:=0;
       while i <= kol do
        if s[i] + leng + min(k,1) <= n
         then
          begin
           inc(leng,s[i] + min(k,1));
            inc(k);
             inc(i);
          end
         else
          begin
           if k = 0
            then
             begin
              writeln('Impossible');
               halt;
             end;
           k:=0;
            leng:=0;
             inc(answer);
          end;
   inc(answer);
  writeln(answer);

End.