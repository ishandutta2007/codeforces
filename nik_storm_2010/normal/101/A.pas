Program A101;
Var
  nom : Array[1..26] of LongInt;
  kol : Array[1..26] of LongInt;
  s : AnsiString;
  k,zapomnit,d,d1,i,j,kolobch : LongInt;


Procedure Del( c : Char );
Var i : LongInt;
 Begin
   i:=1;
   while i<=d do
    if s[i]=c then
                  begin
                   delete(s,i,1);
                   dec(d);
                  end
              else
                  inc(i);
 End;


BEGIN

  readln(s);
  readln(k);
  d:=length(s);
  kolobch:=0;

  for i:=1 to 26 do
   nom[i]:=96+i;

  for i:=1 to d do
   begin
    inc(kol[ord(s[i])-96]);
    if kol[ord(s[i])-96]=1 then inc(kolobch);
   end;

  for i:=1 to 26 do
   for j:=1 to 25 do
    if kol[j]>kol[j+1] then
                           begin
                            zapomnit:=kol[j];
                            kol[j]:=kol[j+1];
                            kol[j+1]:=zapomnit;
                            zapomnit:=nom[j];
                            nom[j]:=nom[j+1];
                            nom[j+1]:=zapomnit;
                           end;

  for i:=1 to 26 do
   if (kol[i]<>0) and (kol[i]<=k) then
                                      begin
                                        d1:=d;
                                        del(chr(nom[i]));
                                        dec(k,d1-d);
                                        dec(kolobch);
                                      end;

  writeln(kolobch);
  writeln(s);

END.