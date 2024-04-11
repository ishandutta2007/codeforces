var
    s,t:string; tek,i:longint;


begin

  readln(s); readln(t); tek:=1;
  for i:=1 to length(t) do
    if s[tek]=t[i] then inc(tek);
  writeln(tek);

end.