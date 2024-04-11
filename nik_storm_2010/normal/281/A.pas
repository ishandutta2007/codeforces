var
    s:ansistring; x:longint;


begin

  readln(s); x:=ord(s[1]);
  if x>=97 then s[1]:=chr(x-32);
  writeln(s);

end.