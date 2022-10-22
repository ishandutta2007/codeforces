uses math;

var n,i,j    : longint;
    cnt,ans  : longint;
    a        : array[1..1000] of longint;
    s        : ansistring;
    b        : boolean;

function gcd(a,b : longint) : longint;

var t : longint;

begin
     while a > 0 do
     begin
          t := a;
          a := b mod a;
          b := t;
     end;
     gcd := t;
end;



begin
     readln(i,j);

     ans := 7 - max(i,j);
     writeln(ans div gcd(ans,6),'/',6 div gcd(ans,6));
end.