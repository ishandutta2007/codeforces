var
 mass:array[1..26]of longint;
 n,m,i,j,c:longint;
begin
 readln(n,m);
 for i := 1 to m do
  mass[i] := n div m;
 n := n mod m;
 while(n<>0)do
 begin
  inc(mass[n]);
  dec(n);
 end;
 c := 0;
 while(c<26)do
 begin
  c := 0;
  for i:=1 to 26 do
   if(mass[i] > 0)then
   begin
    write(char(i+96));
    dec(mass[i]);
   end
   else
    inc(c);
 end;
end.