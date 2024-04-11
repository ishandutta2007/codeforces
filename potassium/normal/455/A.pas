program Codeforces;

var
    i,j            : longint;

    n,x            : longint;

    a              : array[1..100000] of int64;
    dp             : array[0..100000] of int64;

function min64(a,b : int64) : int64; begin if a > b then min64 := b else min64 := a; end;
function max64(a,b : int64) : int64; begin if a > b then max64 := a else max64 := b; end;
function min(a,b : longint) : longint; begin if a > b then min := b else min := a; end;
function max(a,b : longint) : longint; begin if a > b then max := a else max := b; end;

begin
     readln(n);

     for i := 1 to 100000 do
         a[i] := 0;

     for i := 1 to n do
     begin
          read(x);
          inc(a[x]);
     end;

     dp[0] := 0;
     dp[1] := a[1];

     for i := 2 to 100000 do
         dp[i] := max64(dp[i-1],dp[i-2]+a[i]*i);

     writeln(dp[100000]);
end.