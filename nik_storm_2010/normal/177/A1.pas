var
    a:array[1..101,1..101] of longint; sum,n,i,j:longint;


begin

  readln(n); sum:=0;
  for i:=1 to n do
    begin
      for j:=1 to n do read(a[i,j]);
      readln;
    end;
  for i:=1 to n do sum:=sum+a[i,i]+a[i,n-i+1]+a[i,(n+1) div 2]+a[(n+1) div 2,i];
  sum:=sum - 3*a[(n+1) div 2,(n+1) div 2];
  writeln(sum);

end.