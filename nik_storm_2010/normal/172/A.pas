var
   a:array[1..30000] of shortstring;
  n,i,j:longint;


begin

  readln(n);
  for i:=1 to n do readln(a[i]);

  for i:=1 to length(a[1]) do
   for j:=1 to n do
    if a[j,i] <> a[1,i]
     then
    begin
     writeln(i-1);
     halt;
    end;

end.