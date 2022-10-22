uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..3] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

procedure swap(var a,b : longint);

var t : longint;

begin
     t := a;
     a := b;
     b := t;
end;

begin
     readln(s);

     cnt := 0;

     for i := 1 to length(s) do
         if s[i] in ['4','7']
         then inc(cnt);

     if cnt in [4,7]
     then writeln('YES')
     else writeln('NO');

     readln;
end.