var
    a: array[1..200000] of integer;
    n,nom,j,i,y: longint;



procedure output(s:string);
 begin
  writeln(s);
   halt;
 end;

Begin

  readln(n);
   for i:=1 to n do
    read(a[i]);

  for y:=1 to n do
   if a[y] = 1
    then
     for i:=1 to n do
      begin
       j:=y;
        while (j < y+n) and (a[j]=1) do inc(j,i);
         if (j = y+n) and (((j-y) div i)>2) then output('YES');
      end;

  output('NO');

End.