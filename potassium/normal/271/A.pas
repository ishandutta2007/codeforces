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
     readln(n);

     repeat
           inc(n);

           for i := 0 to 9 do
               a[i] := 0;

           str(n,s);

           for i := 1 to length(s) do
           begin
                val(s[i],m);
                inc(a[m]);
           end;

           b := TRUE;

           for i := 0 to 9 do
               if a[i] > 1
               then b := FALSE;
     until b = TRUE;

     writeln(n);
end.