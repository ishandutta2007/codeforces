uses math;

var n           : int64;
    i,j         : longint;
    x,y         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(n);

     for i := 1 to n do
     begin
          readln(x,y);
          if (x+y) mod 2 = 1
          then cnt := 1;

          a[1] := a[1] + x;
          a[2] := a[2] + y;
     end;

     if (a[1] mod 2 = 0) AND (a[2] mod 2 = 0)
     then writeln(0);

     if (a[1] mod 2 = 1) AND (a[2] mod 2 = 1) AND (cnt = 1)
     then writeln(1);

     if ((a[1]+a[2]) mod 2 = 1) OR ((a[1] mod 2 = 1) AND (a[2] mod 2 = 1) AND (cnt = 0))
     then writeln(-1);
end.