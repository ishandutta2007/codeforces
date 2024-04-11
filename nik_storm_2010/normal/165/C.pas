var
  one : array[0..1000001] of int64;
   k, kol1,k1,k2 : int64; answer : int64; i,leng:longint;
    s : ansistring;


begin

  readln(k); readln(s);
   leng:=length(s); kol1:=0;
  for i:=1 to leng do
   begin
    if s[i] = '1'
     then
      begin
       inc(kol1);
       one[kol1]:=i;
      end;
   end;

  answer:=0; s:=s+'1';
   if k=0
    then
     begin
      kol1:=0;
       for i:=1 to leng+1 do
        begin
         if s[i] = '1'
          then
           begin
            answer:=answer + ((kol1+1) * kol1 div 2);
            kol1:=0;
           end
          else
           begin
            inc(kol1);
           end;
        end;
     end
    else
     begin
      if (kol1 >= k)
       then
        begin
         one[0]:=0; one[kol1+1]:=leng+1;
          for i:=k to kol1 do
           begin
            k1:=one[i-k+1] - one[i-k]; k2:=one[i+1] - one[i];
            answer:=answer + k1 * k2;
           end;
         end;
     end;
  writeln(answer);

end.