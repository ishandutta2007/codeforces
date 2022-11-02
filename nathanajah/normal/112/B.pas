var
n:longint;
x,y:longint;

begin
readln(n,x,y);
if ((x=(n div 2)) or (x=(n div 2)+1)) and ((y=(n div 2)) or (y=(n div 2)+1)) then
  writeln('NO')
else
  writeln('YES');
end.