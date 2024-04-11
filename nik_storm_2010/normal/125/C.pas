Var
    a: array[1..1000,0..10000] of longint;
     tek,n,kol,i,j,koef: longint;


function f(kol:longint) : longint;
var c:longint;
 begin
  c:=trunc((1+kol)/2*kol);
   exit(c);
 end;


Begin

  readln(n);
   kol:=1;
    while f(kol) <= n do inc(kol);

  tek:=0;
   for i:=1 to kol do
    begin

     koef:=0;
      for j:=1 to kol-1 do
       if a[i,j] = 0
        then
         begin
          inc(tek);
           inc(a[i,0]);
            a[i,a[i,0]]:=tek;
             inc(koef);
             inc(a[i+koef,0]);
            a[i+koef,a[i+koef,0]]:=tek;
         end;

    end;

  writeln(kol);
   for i:=1 to kol do
    begin

     for j:=1 to kol-1 do write(a[i,j],' ');
      writeln;

    end;

End.