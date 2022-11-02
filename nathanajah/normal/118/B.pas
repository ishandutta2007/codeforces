var
n:longint;
i,j:longint;


begin
readln(n);
for i:=1 to 2*n do
  write(' ');
writeln(0);
for i:=1 to n do
begin
  for j:=1 to 2*(n-i) do
    write(' ');
  for j:=0 to i-1 do
    write(j,' ');
  write(i,' ');
  for j:=i-1 downto 0 do
    if j=0 then
      writeln(j)
    else
      write(j,' ');
end;
for i:=n-1 downto 1 do
begin
  for j:=1 to 2*(n-i) do
    write(' ');
  for j:=0 to i-1 do
    write(j,' ');
  write(i,' ');
  for j:=i-1 downto 0 do
    if j=0 then
      writeln(j)
    else
      write(j,' ');
end;
if n>0 then
begin
for i:=1 to 2*n do
  write(' ');
write(0);
end;
end.