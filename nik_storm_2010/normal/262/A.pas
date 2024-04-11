var
    answer,kol,num,i,c,k,n:longint;


begin

  readln(n,k); answer:=0;
  for i:=1 to n do
    begin
      read(c); kol:=0;
      while c<>0 do
        begin
          num:=c mod 10; c:=c div 10;
          if (num=4) or (num=7) then inc(kol);
        end;
      if kol<=k then inc(answer);
    end;
  writeln(answer);

end.