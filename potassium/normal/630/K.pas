var n           : int64;
    i,j         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(n);

     writeln(n - n div 2 - n div 3 - n div 5 - n div 7 + n div 6 + n div 10 + n div 14 + n div 15 + n div 21 + n div 35 - n div 30 - n div 42 - n div 70 - n div 105 + n div 210);
end.