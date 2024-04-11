uses math;

const inf = 2147483647;

var n,m,p,q,t   : longint;
    l,r         : longint;
    i,j,k       : longint;
    x,y,z       : longint;
    cnt,ans     : int64;
    a           : array[1..1048575] of longint;
    s,s1,s2     : ansistring;
    c           : char;
    b           : boolean;

    depth       : longint;
    fn          : longint;

procedure swap (var a,b : longint);var t : longint;begin t := a;a := b;b := t;end;
procedure swapc(var a,b : char)   ;var t : char;   begin t := a;a := b;b := t;end;

function gcd  (a,b : longint):longint;var t : longint;begin while a > 0 do begin t := a;a := b mod a;b := t;end;gcd := b;end;

begin
     readln(n);

     k := 5;

     repeat
           if n > k
           then begin
                     n := n - k;
                     k := k * 2;
                end
     until n <= k;

     case ((n-1) div (k div 5)) of
                                  0 : writeln('Sheldon');
                                  1 : writeln('Leonard');
                                  2 : writeln('Penny');
                                  3 : writeln('Rajesh');
                                  4 : writeln('Howard');
     end;
end.