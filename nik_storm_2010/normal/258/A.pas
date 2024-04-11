var
    s:ansistring; d,i:longint;


begin

  readln(s); d:=length(s);
  for i:=1 to d do
    if s[i]='0' then
    begin
      delete(s,i,1); writeln(s);
      halt;
    end;
  delete(s,1,1); writeln(s);

end.