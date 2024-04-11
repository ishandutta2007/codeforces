uses math;

var n,i,j    : longint;
    cnt,ans  : longint;
    a        : array[1..1000] of longint;
    s        : ansistring;
    b        : boolean;

begin
     readln(s);

     b := FALSE;

     for i := 1 to length(s) do
         if s[i] in ['H','Q','9']
         then b := TRUE;

     if b
     then writeln('YES')
     else writeln('NO');
end.