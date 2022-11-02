var
  a : array[1..12] of longint;
   i,j,tmp,answer,k : longint;


begin

  readln(k);
   for i:=1 to 12 do read(a[i]);

  for i:=1 to 12 do
   for j:=i+1 to 12 do
    if a[i] > a[j]
     then
      begin
       tmp:=a[i];
        a[i]:=a[j];
       a[j]:=tmp;
      end;

    answer:=0;
  for i:=12 downto 1 do
   begin
    if k<=0 then break;
     k:=k-a[i];
    inc(answer);
   end;
  if k<=0 then writeln(answer) else writeln(-1);

end.