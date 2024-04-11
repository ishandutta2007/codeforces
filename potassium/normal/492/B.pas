uses math,sysutils;

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

function gcd  (a,b : longint):longint;var t : longint;begin while a > 0 do begin t := a;a := b mod a;b := t;end;gcd := b;end;

begin
     readln(n,l);

     for i := 1 to n do
         read(a[i]);

     for i := 1 to n-1 do
         for j := 1 to n-i do
             if a[j] > a[j+1]
             then swap(a[j],a[j+1]);

     ans := max(a[1],l-a[n])*2;

     for i := 1 to n-1 do
         ans := max(ans,(a[i+1]-a[i]));

     writeln(ans/2:0:9);
end.