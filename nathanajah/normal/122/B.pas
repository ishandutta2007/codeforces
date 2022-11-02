var
s:string;
i:longint;
n:longint;
count4,count7:longint;

begin
readln(s);
for i:=1 to length(s) do
begin
	if s[i]='4' then inc(count4)
	else if s[i]='7' then inc(count7);
end;
if (count4=0) and (count7=0) then
	writeln(-1)
else
if count4>=count7 then
	writeln('4')
else
	writeln('7');
end.