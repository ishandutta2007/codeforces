Program A88;
Const
  mas : Array[1..12] of String = ('C','C#','D','D#','E','F','F#','G','G#','A','B','H');

Var
  s,s1,s2,s3 : String;
  kol1,kol2,i,j,nom1,nom2,nom3,d,i1 : LongInt;


Procedure Opred( nom1,nom2,nom3 : LongInt );
 Begin

  if nom2<nom1 then kol1:=nom2+12-nom1 else kol1:=nom2-nom1;
  if nom3<nom2 then kol2:=nom3+12-nom2 else kol2:=nom3-nom2;

  if (kol1=4) and (kol2=3) then begin writeln('major'); halt; end;
  if (kol1=3) and (kol2=4) then begin writeln('minor'); halt; end;

 End;

BEGIN

  readln(s);

  i:=1; d:=length(s);

  while s[i]<>' '   do inc(i);
  s1:=copy(s,1,i-1);   inc(i); i1:=i;
  while s[i]<>' '   do inc(i);
  s2:=copy(s,i1,i-i1); inc(i);
  s3:=copy(s,i,d-i+1);

  for i:=1 to 12 do
   begin
    if mas[i]=s1 then nom1:=i;
    if mas[i]=s2 then nom2:=i;
    if mas[i]=s3 then nom3:=i;
   end;

  Opred(nom1,nom2,nom3);
  Opred(nom1,nom3,nom2);
  Opred(nom2,nom1,nom3);
  Opred(nom2,nom3,nom1);
  Opred(nom3,nom1,nom2);
  Opred(nom3,nom2,nom1);

  writeln('strange');

END.