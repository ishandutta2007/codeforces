var pred,d,n,answer,i,tek:longint;


begin

  readln(d); readln(n);
   answer:=0;
  read(pred);

  for i:=2 to n do
   begin
    read(tek);
     answer:=answer + (d-pred);
    pred:=tek;
   end;
  writeln(answer);

end.