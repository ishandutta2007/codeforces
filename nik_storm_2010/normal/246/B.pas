var
    answer,sum,n,i,a:longint;


begin

  readln(n); sum:=0;
  for i:=1 to n do
    begin
      read(a); sum:=sum+a;
    end;
  if sum mod n=0 then writeln(n) else writeln(n-1);

end.