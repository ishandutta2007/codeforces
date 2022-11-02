var
  n,x:longint;

procedure print(x:longint);
var
  i:longint;
begin
  if (x>=5) then write('-O|') else write('O-|');
  if (x>=5) then x:=x-5;
  for i:=1 to x do write('O');
  write('-');
  for i:=1 to 4-x do write('O');
  writeln;
end;

begin
  readln(n);
  if (n=0) then print(0);
  while (n<>0) do
  begin
    x:=n mod 10;
    print(x);
    n:=n div 10;
  end;
end.