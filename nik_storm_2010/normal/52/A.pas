Program A52;
Var
  i,kol1,kol2,kol3,ch,raz1,raz2,raz3,n,min : LongInt;


BEGIN

  readln(n); kol1:=0; kol2:=0; kol3:=0;
  for i:=1 to n do
   begin
    read(ch);
    if ch=1 then inc(kol1);
    if ch=2 then inc(kol2);
    if ch=3 then inc(kol3);
   end;

  raz1:=n-kol1;
  raz2:=n-kol2;
  raz3:=n-kol3;

  min:=raz1;
  if min>raz2 then min:=raz2;
  if min>raz3 then min:=raz3;

  writeln(min);


END.