program Stones;

var n,i        : longint;
    a          : array[1..50] of char;
    cnt        : longint;

begin
     readln(n);

     for i := 1 to n do
     begin
          read(a[i]);
          if a[i] = a[i-1]
          then inc(cnt);
     end;

     writeln(cnt);
end.