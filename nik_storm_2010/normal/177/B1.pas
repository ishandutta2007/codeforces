var
    answer,pred,del,n,i:longint;


begin

  readln(n); answer:=n;
  while n<>1 do
    begin
      pred:=round(sqrt(n)); del:=-1;
      for i:=2 to pred do
        if n mod i=0 then
        begin
          del:=i; break;
        end;
      if del=-1 then del:=n;
      n:=n div del; answer:=answer+n;
    end;
  writeln(answer);

end.