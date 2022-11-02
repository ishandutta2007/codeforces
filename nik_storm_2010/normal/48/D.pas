var
    kol: array[1..100000] of longint;
    nom: array[1..100000] of longint;
    a: array[1..100000] of longint;
    n,ch,pred,maxnom,maxel,i: longint;



Begin

  maxel:=0;
   readln(n);
    for i:=1 to n do
     begin
      read(a[i]);
       inc(kol[a[i]]);
        if a[i]>maxel then maxel:=a[i];
     end;

  maxnom:=0;
   pred:=MaxLongint;
    for i:=1 to maxel do
     if kol[i] <= pred
      then
       begin
        pred:=kol[i];
         if kol[i] > maxnom then maxnom:=kol[i];
       end
      else
       begin
        writeln(-1);
         halt;
       end;

  writeln(maxnom);
   for i:=1 to n do
    begin
     inc(nom[a[i]]);
      write(nom[a[i]],' ');
    end;

End.