var
    a:array[1..50] of char; answer,n,i:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  answer:=0;
  for i:=2 to n do
    if a[i]=a[i-1] then inc(answer);
  writeln(answer);

end.