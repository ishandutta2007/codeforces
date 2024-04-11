program Codeforces;

var
    s              : ansistring;
    n              : longint;
    x              : longint;

    i,j            : longint;

    min,max        : longint;

    a              : array[1..100] of longint;

begin
     readln(n);

     for i := 1 to 100 do
         a[i] := 0;

     for i := 1 to n do
     begin
          read(x);

          inc(a[x]);
     end;

     max := 0;

     for i := 1 to 100 do
     begin
          if a[i] > max
          then max := a[i];
     end;

     writeln(max);
end.