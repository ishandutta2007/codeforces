var
s:string;
i:longint;
lock:boolean;

begin
readln(s);
lock:=true;

for i:=2 to length(s) do
  lock:=lock and (s[i]>='A') and (s[i]<='Z');
if not lock then
  writeln(s)
else
begin
for i:=1 to length(s) do
  if (s[i]>='A') and (s[i]<='Z') then
    write(chr(ord(s[i])+32))
  else
    write(chr(ord(s[i])-32));
writeln;
end;
end.