var
    a:array[1..100000] of longint; sum,min,n,k,i:longint;


begin

  readln(n,k); for i:=1 to n do read(a[i]);
  for i:=1 to n do
    if (k>0) and (a[i]<0) then
    begin
      a[i]:=-a[i]; dec(k);
    end
    else break;
  min:=maxlongint; sum:=0;
  for i:=1 to n do
    begin
      if a[i]<min then min:=a[i];
      sum:=sum+a[i];
    end;
  if k mod 2=1 then sum:=sum-2*min;
  writeln(sum);

end.