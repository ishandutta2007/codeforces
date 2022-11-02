Program A112;
Var
  s1,s2 : string;
  i : longint;


BEGIN

 readln(s1);
 readln(s2);

 for i:=1 to length(s1) do
  begin
   if ord(s1[i])<97 then s1[i]:=chr(ord(s1[i])+32);
   if ord(s2[i])<97 then s2[i]:=chr(ord(s2[i])+32);
  end;

 if s1=s2 then writeln('0');
 if s1<s2 then writeln('-1');
 if s1>s2 then writeln('1');

END.