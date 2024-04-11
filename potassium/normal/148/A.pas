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

function gcd  (a,b : longint):longint;var t : longint;begin while a > 0 do begin t := a;a := b mod a;b := t;end;gcd := b;end;

begin
     readln(n);
     readln(m);
     readln(p);
     readln(q);
     readln(k);

     ans := 0;
     for i := 1 to 15 do
     begin
          cnt := 0;
          l := 1;
          if (i AND 1 = 1) then begin inc(cnt); l := (l*n div gcd(l,n));end;
          if (i AND 2 = 2) then begin inc(cnt); l := (l*m div gcd(l,m));end;
          if (i AND 4 = 4) then begin inc(cnt); l := (l*p div gcd(l,p));end;
          if (i AND 8 = 8) then begin inc(cnt); l := (l*q div gcd(l,q));end;

          if (cnt mod 2 = 0)
          then ans := ans - (k div l)
          else ans := ans + (k div l);
     end;

     writeln(ans);
end.