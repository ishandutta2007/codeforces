Program A109;
Var
  n,kol4,kol7 : longint;



Procedure vyvod( kol1,kol2:longint );
Var i:longint;
 Begin
  if kol1+kol2=0 then begin writeln(-1); halt; end;
  for i:=1 to kol1 do write('4');
  for i:=1 to kol2 do write('7');
  halt;
 End;


BEGIN

  readln(n);

  kol4:=0; kol7:=0;
  while n>=7 do
   begin
    inc(kol7);
    dec(n,7);
   end;

  if n=0 then vyvod(0,kol7);
  if n mod 4 = 0 then vyvod(n div 4,kol7);

  while kol7<>0 do
   begin
    dec(kol7);
    n:=n+7;
    kol4:=kol4+n div 4;
    n:=n mod 4;
    if n=0 then vyvod(kol4,kol7);
   end;

  if n<>0 then vyvod(0,0)
          else vyvod(kol4,kol7);


END.