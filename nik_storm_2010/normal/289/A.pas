var
    sum,max,n,k,i,a,b:longint;


begin

  readln(n,k); sum:=0;
  for i:=1 to n do
    begin
      readln(a,b);
      sum:=sum+(b-a+1);
    end;
  if sum mod k=0 then max:=sum else max:=sum+(k-sum mod k);
  writeln(max-sum);

end.