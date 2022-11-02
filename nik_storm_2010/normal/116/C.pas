uses math;
var
 a : array[1..2000] of longint;
  n,i,answer,tek,j : longint;


begin

  readln(n);
   for i:=1 to n do readln(a[i]);
  answer:=0;

  for i:=1 to n do
   begin
    tek:=1;
     j:=a[i];
      while j<>-1 do
       begin
        inc(tek);
        j:=a[j];
       end;
    answer:=max(answer,tek);
   end;
  writeln(answer);

end.