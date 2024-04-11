var
    answer,n,i:longint;


begin

  readln(n); answer:=n;
  for i:=2 to n do
    begin
      answer:=answer + (n-i)*i + 1;
    end;
  writeln(answer);

end.