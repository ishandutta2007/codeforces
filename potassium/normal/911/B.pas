program TwoCakes;

var n,a,b,i,ans : longint;

function max(a,b : longint):longint;

begin
     if a > b
     then max := a
     else max := b;
end;

function min(a,b : longint):longint;

begin
     if a < b
     then min := a
     else min := b;
end;


begin
     readln(n,a,b);

     for i := 1 to n-1 do
         ans := max(ans, min(a div i, b div (n-i)));

     writeln(ans);

     readln;
end.