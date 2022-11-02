var
    answer,c1,c2,c3,n,i:longint;


begin

  readln(n); answer:=0;
  for i:=1 to n do
    begin
      readln(c1,c2,c3);
      if c1+c2+c3>=2 then inc(answer);
    end;
  writeln(answer);

end.