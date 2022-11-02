var
s:string;
i:longint;

function downcase(x:char):char;
begin
  if (x>='A') and (x<='Z') then
    downcase:=chr(ord(x)+32)
  else downcase:=x;
end;

function cek(x:char):boolean;
begin
  x:=upcase(x);
  cek := (x='A') or (x='I') or (x='U') or (x='O') or (x='E') or (x='Y');
end;




begin
readln(s);
for i:=1 to length(s) do
  if not cek(s[i]) then
  begin
    write('.');
    write(downcase(s[i]));
  end;
writeln;
end.