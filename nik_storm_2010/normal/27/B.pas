var
    kolgame: array[1..50] of longint;
    lotlose: array[1..50] of longint;
    kol: array[0..50] of longint;
    g: array[0..50,1..50] of longint;
    n,i,a,b,nom1,nom2,koll,j: longint;



Begin

  readln(n);
   koll:=n*(n-1) div 2-1;
    for i:=1 to koll do
     begin
      readln(a,b);
       inc(lotlose[b]);
        inc(kolgame[a]);
         inc(kolgame[b]);
     end;

  nom1:=0; nom2:=0;
   for i:=1 to n do
    begin

      if kolgame[i] <> n-1
       then
        if nom1=0
         then nom1:=i
         else nom2:=i;
      kol[lotlose[i]]:=1;

    end;

  a:=0; b:=0;
   for i:=0 to n-1 do
    if kol[i] = 0
     then
      begin
       a:=i;
        break;
      end;

  if lotlose[nom1] + 1 = a then writeln(nom2,' ',nom1)
                           else writeln(nom1,' ',nom2);

End.