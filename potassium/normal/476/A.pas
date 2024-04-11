program Codeforces;

uses math;

var
    i,j            : longint;

    n,m            : longint;

function min(a,b : longint) : longint; begin if a > b then min := b else min := a; end;
function max(a,b : longint) : longint; begin if a > b then max := a else max := b; end;

begin
     readln(n,m);

     if m > n
     then writeln(-1)
     else writeln(ceil(n/m/2)*m);
end.