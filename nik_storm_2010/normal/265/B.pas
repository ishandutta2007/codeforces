var
    a:array[1..100000] of longint; time,h,i,n:longint;


begin

  readln(n); for i:=1 to n do readln(a[i]);
  time:=a[1]+1; h:=a[1];
  for i:=2 to n do
    begin
      time:=time + abs(h-a[i]) + 2;
      h:=a[i];
    end;
  writeln(time);

end.