Var
    g,gnext: array[1..100,1..100] of longint;
     ans: array[1..100] of longint;
      n,m,i,j,a,b,tek,pred,kol,answer: longint;



Begin

  readln(n,m);
   for i:=1 to m do
    begin
     readln(a,b);
      g[a,b]:=1; g[b,a]:=1;
       gnext[a,b]:=1; gnext[b,a]:=1;
    end;

  pred:=MaxLongint; answer:=0;
   while pred<>0 do
    begin

      for i:=1 to n do for j:=1 to n do g[i,j]:=gnext[i,j];
      tek:=0;
       for i:=1 to n do
        begin

          kol:=0;
           for j:=1 to n do
            if g[i,j]=1 then inc(kol);

          if kol=1
           then
            begin
             inc(tek);
              for j:=1 to n do begin gnext[i,j]:=0; gnext[j,i]:=0; end;
            end;

        end;

       if tek<>0 then inc(answer);
        pred:=tek;

    end;
  writeln(answer);

End.