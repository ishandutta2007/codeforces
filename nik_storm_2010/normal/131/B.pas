 var
  kol : array[-10..10] of int64;
   i : longint;
    answer,c,n : int64;




begin

  readln(n);
   for i:=1 to n do
    begin
     read(c);
      inc(kol[c]);
    end;

  answer:=0;
   for i:=1 to 10 do answer:=answer + kol[i]*kol[-i];

  if kol[0]<>0 then answer:=answer + trunc( ((kol[0]-1)/2) * kol[0] );
   writeln(answer);

end.