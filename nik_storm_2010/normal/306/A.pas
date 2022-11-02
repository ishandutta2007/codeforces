var
    a:array[1..100] of longint; n,m,i,j:longint;


begin

  readln(n,m); i:=1;
  while n<>0 do
    begin
      inc(a[i]); dec(n); inc(i);
      if i>m then i:=1;
    end;
  for j:=1 to m do write(a[j],' ');

end.