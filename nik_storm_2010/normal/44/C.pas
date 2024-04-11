Var
    kol: array[1..100] of longint;
      n,m,k,i,a,b: longint;


Begin

  readln(n,m);
   for k:=1 to m do
    begin

      readln(a,b);
       for i:=a to b do inc(kol[i]);

    end;

  for i:=1 to n do
   if (kol[i]=0) or (kol[i]>1)
    then
     begin
      writeln(i,' ',kol[i]);
       halt;
     end;
  writeln('OK');

End.