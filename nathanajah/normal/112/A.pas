var
s1,s2:string;

begin
readln(s1);
readln(s2);
s1:=upcase(s1);
s2:=upcase(s2);
if s1>s2 then writeln(1)
else if s1=s2 then writeln(0)
else writeln(-1);
end.