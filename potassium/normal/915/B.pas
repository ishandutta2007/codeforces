uses math;

var n,m,k,p     : int64;
    l,r         : longint;
    i,j         : longint;
    x,y         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

function dist(a,b : longint) : longint;

begin
     if a > b
     then dist := a-b
     else dist := b-a;
end;

begin
     readln(n,p,l,r);

     if (l > 1) AND (r < n)
     then begin
               if p < l
               then ans := dist(r,p) + 2;

               if p > r
               then ans := dist(l,p) + 2;

               if (p >= l) AND (p <= r)
               then ans := min(dist(l,p),dist(r,p)) + dist(r,l) + 2;
          end;

     if l = 1
     then ans := dist(r,p) + 1;

     if r = n
     then ans := dist(l,p) + 1;

     if (l = 1) AND (r = n)
     then ans := 0;

     writeln(ans);
end.