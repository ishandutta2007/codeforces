uses math;

var n,m         : int64;
    i,j         : longint;
    x,y         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(n);
     readln(m);

     if log2(m) >= n
     then writeln(m mod round(power(2,n)))
     else writeln(m);
end.