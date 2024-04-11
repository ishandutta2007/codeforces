uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y         : int64;
    cnt,ans     : int64;
    a           : array[1..100] of longint;
    s,s1,s2     : ansistring;
    c           : array[1..5] of char;
    b           : boolean;

procedure swap(var a,b : longint);

var t : longint;

begin
     t := a;
     a := b;
     b := t;
end;

begin
     readln(n);

     if (n mod 4 = 0) OR (n mod 7 = 0) OR (n mod 47 = 0) OR (n mod 74 = 0) OR (n mod 447 = 0) OR (n mod 474 = 0) OR (n mod 477 = 0) OR (n mod 747 = 0) OR (n mod 774 = 0)
     then writeln('YES')
     else writeln('NO');
end.