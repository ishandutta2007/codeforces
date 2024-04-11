var
    a:array[1..2,1..100] of longint; ans,n,i,j:longint;


begin

  readln(n);
  for i:=1 to n do readln(a[1,i],a[2,i]);
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
    if i<>j then
      begin
        if a[1,i]=a[2,j] then inc(ans);
      end;
  writeln(ans);

end.