var
   n,m,k,answer:int64; i:longint;



begin

  readln(n,m,k);
  if (k>n) or (k=1)
   then
    begin
     answer:=1;
      for i:=1 to n do answer:=answer*m mod 1000000007;
      writeln(answer);
     halt;
    end;

  if k=n
   then
    begin
     answer:=1;
      for i:=1 to n div 2 do answer:=answer*m mod 1000000007;
       if n mod 2 <> 0 then answer:=answer*m mod 1000000007;
      writeln(answer);
     halt;
    end;

  if k<n
   then
    begin
     if (k mod 2 = 0)
      then
       begin
        writeln(m);
       end
      else
       begin
        writeln(m*m);
       end;
     halt;
    end;

end.