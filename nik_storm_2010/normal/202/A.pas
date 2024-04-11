var
   d,kol,i:longint; max:char;
    s:string;


begin

  readln(s); d:=length(s);
   max:='1'; kol:=0;
  for i:=1 to d do
   begin
    if s[i] > max
     then
      begin
       max:=s[i];
       kol:=1;
      end
     else
      begin
       if s[i]=max then inc(kol);
      end;
   end;
  for i:=1 to kol do write(max);

end.