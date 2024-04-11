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
     readln(n);

     for i := 1 to n do
     begin
          readln(x,y,z);
          a[1] := a[1] + x;
          a[2] := a[2] + y;
          a[3] := a[3] + z;
     end;

     if (a[1] = 0) AND (a[2] = 0) AND (a[3] = 0)
     then writeln('YES')
     else writeln('NO');
end.