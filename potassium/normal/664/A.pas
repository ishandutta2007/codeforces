var n,i,j       : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(s);

     s1 := copy(s,1,length(s) div 2);
     s2 := copy(s,length(s) div 2 + 2,length(s) - length(s) div 2);

     if s1 = s2 then writeln(s1) else writeln(1);
end.