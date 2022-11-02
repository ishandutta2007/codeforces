var
    a:array[1..200] of longint; min,sum,kol,n,i:longint;


begin

  readln(n);
  kol:=0; min:=maxlongint; sum:=0;
  for i:=1 to 2*n-1 do
    begin
      read(a[i]);
      if abs(a[i])<min then min:=abs(a[i]);
      if a[i]<=0 then kol:=kol+1;
      sum:=sum+abs(a[i]);
    end;
  if (n mod 2=0) and (kol mod 2=1) then writeln(sum-min*2) else writeln(sum);

end.