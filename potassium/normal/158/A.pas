program NextRound;

var n,k,i         : longint;
    cnt           : longint;
    a             : array[1..100] of longint;

begin
     readln(n,k);

     for i := 1 to n do
          read(a[i]);

     for i := 1 to n do
         if (a[i] >= a[k]) AND (a[i] > 0)
         then inc(cnt);

     writeln(cnt);
end.