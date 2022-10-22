uses math;

var n           : int64;
    i,j         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(n);

     n := abs(n);

     ans := ceil((sqrt(8*n+1)-1)/2);

     while (ans+1) div 2 mod 2 <> n mod 2 do
           inc(ans);

     writeln(ans);
end.