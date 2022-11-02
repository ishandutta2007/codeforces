var
  s : string;
   d,i,pred,a,tek : longint;




procedure zer(a:longint; var c:longint);
var b:array[1..10] of longint;
     kol,i,t:longint;
 begin

   kol:=0; fillchar(b,sizeof(b),0);
    while a<>0 do
     begin

       inc(kol);
        b[kol]:=a mod 2;
       a:=a div 2;

     end;

   c:=0; t:=1;
    for i:=8 downto 1 do
     begin

       c:=c+b[i]*t;
        t:=t*2;

     end;

 end;




begin

  readln(s);
   d:=length(s); pred:=0;
    for i:=1 to d do
     begin

       a:=ord(s[i]);
        zer(a,tek);
       writeln( abs(pred-tek+256) mod 256);

       pred:=tek;

     end;

end.