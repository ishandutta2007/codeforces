uses
    math;
var
    mas : array[0..1000000] of longint;
    kol : array[0..1000000] of longint;
    a,b,c,d : array[0..10] of longint;
    i,j,n,m,ntek,nach,nom : longint;



Begin

  mas[0]:=1;
  a[0]:=MaxLongint;
   b[0]:=1;
    readln(n,m,c[0],d[0]);
     for i:=1 to m do
      readln(a[i],b[i],c[i],d[i]);

  for i:=0 to m do
   begin

    ntek:=n;
    for j:=100000 downto 1 do
     if mas[j] = 1
      then
       begin
        ntek:=kol[j]; nach:=a[i]; nom:=j;
         while (ntek-c[i]>=0) and (nach-b[i]>=0) do
          begin
           nom:=nom+d[i];
            mas[nom]:=1;
             ntek:=ntek-c[i];
              nach:=nach-b[i];
               kol[nom]:=max(ntek,kol[nom]);
          end;
       end;
     if (n-c[i]>=0) and (a[i]-b[i]>=0)
      then
       begin
        ntek:=n; nach:=a[i]; nom:=0;
         while (ntek-c[i]>=0) and (nach-b[i]>=0) do
          begin
           nom:=nom+d[i];
            mas[nom]:=1;
             ntek:=ntek-c[i];
              nach:=nach-b[i];
               kol[nom]:=max(ntek,kol[nom]);
         end;
       end;

   end;

  for i:=100000 downto 0 do
   if mas[i] = 1 then
    begin
     writeln(i);
      halt;
    end;

End.