program strom;
var
    a: array[1..100000] of integer;
    ot: array[1..5] of longint;
    ans: array[1..2,1..5] of longint;
    n,i,kol1,kol2,m,nom,nomo,j: longint;


procedure min(a,b:longint; var m : longint);
 begin
  if a<b then m:=a
          else m:=b;
 end;


Begin

  readln(n);
   readln(kol1,kol2);
    for i:=1 to n do
     begin
      read(a[i]);
       inc(ot[a[i]]);
     end;

    if kol1 = kol2
     then
      begin
       for i:=1 to kol1 do write('1 ');
        for i:=1 to kol2 do write('2 ');
         halt;
      end;

    min(kol1,kol2,m);
     if kol1 = m then begin nom:=1; for i:=1 to 5 do ans[2,i]:=ot[i]; end
                  else begin nom:=2; for i:=1 to 5 do ans[1,i]:=ot[i]; end;
      nomo:=3-nom;

    for i:=1 to m do
     for j:=5 downto 1 do
      if ot[j] <> 0
       then
        begin
         inc(ans[nom,j]);
          dec(ans[nomo,j]);
           dec(ot[j]);
           break;
        end;

   for i:=1 to n do
    if ( ans[1,a[i]] <> 0 )
     then
      begin
       dec(ans[1,a[i]]);
       write('1 ')
      end
     else
      write('2 ');

End.