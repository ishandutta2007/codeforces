uses math;
const inf = 2147483647;
var n,m,p,q,t   : longint;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[0..1000] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

begin
     readln(s1);
     readln(s2);

     b := TRUE;

     if length(s1) <> length(s2)
     then b := FALSE
     else for i := 1 to length(s1) do
              if (s1[i] <> s2[length(s2)+1-i])
              then b := FALSE;

     if (b = TRUE)
     then writeln('YES')
     else writeln('NO');
end.