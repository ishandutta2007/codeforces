uses math;
const inf = 2147483647;
var n,m,p,q,t   : longint;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

begin
     readln(n,m);

     for i := 1 to m do
         read(a[i]);

     readln;

     for i := 1 to m-1 do
         for j := 1 to m-i do
             if a[j] > a[j+1]
             then swap(a[j],a[j+1]);

     ans := inf;

     for i := 1 to m-n+1 do
          ans := min(ans,a[i+n-1]-a[i]);

     writeln(ans);
end.