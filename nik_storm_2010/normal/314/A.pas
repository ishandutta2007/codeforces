var
    a:array[1..200000] of int64; rate,cur,ost,kol,i,n,k:int64; test:longint;


begin

  readln(n,k); for test:=1 to n do read(a[test]);
  cur:=0; kol:=1; i:=2; ost:=n;
  while i<=n do
    begin
      rate:=cur-(kol*(ost-(kol+1))*a[i]);
      if rate<k then
      begin
        writeln(i); dec(ost);
      end
        else
      begin
        kol:=kol+1; cur:=cur+a[i]*(kol-1);
      end;
      inc(i);
    end;

end.