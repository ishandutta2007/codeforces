var
  a : array[1..100] of longint;
   n,i,c : longint;




begin

  readln(n);
   for i:=1 to n do
    begin

      read(c);
       a[c]:=i;

    end;
  for i:=1 to n do write(a[i],' ');

end.