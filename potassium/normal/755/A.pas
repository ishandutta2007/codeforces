program Hypothesis;

var n              : longint;

begin
     readln(n);

     if n < 3
     then n := n + 4;

     writeln(n - 2);
end.