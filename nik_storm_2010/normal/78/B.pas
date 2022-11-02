Program B78;
Var
  n,kol : longint;
  stas : char;


Begin

  readln(n);
   n:=n-7;
    write('ROYGBIV');
   stas:='V';
  kol:=1;

  while n<>0 do
   begin
    if stas='V' then stas:='G' else
     if stas='G' then stas:='B' else
      if stas='B' then stas:='I' else
       if stas='I' then stas:='V';
    write(stas);
     dec(n);
   end;

End.