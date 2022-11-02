var
    a:array[1..2,1..100000] of longint; ans:array[1..100000] of longint;
     n,i,x:longint;


begin

  readln(n);
   for i:=1 to n do
    begin
     read(x);
     a[1,x]:=i;
    end;
  readln;
   for i:=1 to n do
    begin
     read(x);
     a[2,x]:=i;
    end;

  for i:=1 to n do ans[a[2,i]]:=a[1,i];
   for i:=1 to n do
  write(ans[i],' ');


end.