var
    a:array[1..50] of longint; kol,tmp,n,k,i,j:longint;


begin

  readln(n,k); for i:=1 to n do read(a[i]);
  for i:=1 to n do
    for j:=i+1 to n do
    if a[i]>a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  for i:=1 to n do
    begin
      kol:=0;
      for j:=1 to n do
        if a[i]<=a[j] then inc(kol);
      if kol=k then
        begin
          writeln(a[i],' ',a[i]);
          halt;
        end;
    end;
  writeln(-1);

end.