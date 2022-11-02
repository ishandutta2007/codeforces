var
    s:ansistring; tek,d,i:longint;


begin

  readln(s); readln(tek); d:=length(s);
  for i:=1 to d do
    begin
    if s[i] in ['A'..'Z'] then s[i]:=chr(ord(s[i])+32);
    end;
  for i:=1 to d do
    begin
    if ord(s[i])<97+tek then s[i]:=upcase(s[i]);
    end;
  writeln(s);

end.