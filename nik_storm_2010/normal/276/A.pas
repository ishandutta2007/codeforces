var
    answer,tek,n,k,f,t,i:longint;


begin

  readln(n,k); answer:=-maxlongint;
  for i:=1 to n do
    begin
      readln(f,t); if t>k then tek:=f-(t-k) else tek:=f;
      if answer<tek then answer:=tek;
    end;
  writeln(answer);

end.