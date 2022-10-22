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

     cnt := 0;

     y := -inf;

     for i := 1 to n do
     begin
          read(x);

          if x >= y
          then inc(cnt)
          else cnt := 1;

          ans := max(ans,cnt);

          y := x;
     end;

     writeln(ans);
end.