uses math;

var n,m,k       : int64;
    i,j         : longint;
    x,y         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(n,k);

     ans := 2147483647;

     for i := 1 to n do
     begin
          read(a[i]);

          if (k mod a[i] = 0)
          then ans := min(ans, k div a[i]);
     end;

     writeln(ans);
end.