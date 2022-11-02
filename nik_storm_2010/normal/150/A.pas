var
   del : array[1..64] of int64;
    q, kol, i, pred : int64;


begin

  readln(q);

   kol:=0; i:=2; pred:=round(sqrt(q));
    while i<=pred do
     begin
      while q mod i = 0 do
       begin
        inc(kol);
         del[kol]:=i;
        q:=q div i;
       end;
       inc(i);
      if q=1 then break;
     end;
    if q<>1
     then
      begin
       inc(kol);
       del[kol]:=q;
      end;

   if kol<2
    then
     begin
      writeln(1);
      writeln(0);
     end
    else
     begin
      if kol=2
       then
        begin
         writeln(2);
        end
       else
        begin
         writeln(1);
         writeln(del[1]*del[2]);
        end;
     end;

end.