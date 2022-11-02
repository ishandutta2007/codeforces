var
    a:array[1..2000000] of longint; add,n,x,y,i,j:longint;


begin

  readln(n); for i:=1 to n do a[i]:=i;
  for i:=2 to n do
  begin
    inc(add); y:=n+add;
    if n mod i=0 then x:=n+add-i else x:=n+add-(n mod i);
    while x>0 do
      begin
        a[y]:=a[x]; y:=x; x:=x-i;
      end;
  end;
  for i:=1 to n do write(a[i+add],' ');

end.