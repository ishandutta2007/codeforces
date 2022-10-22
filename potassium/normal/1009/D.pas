program Codeforces;

var
    i,j,k          : longint;

    n,m            : longint;
    cnt            : longint;
    ans            : longint;

    edge           : array[1..100000,1..2] of longint;

function min64(a,b : int64) : int64; begin if a > b then min64 := b else min64 := a; end;
function max64(a,b : int64) : int64; begin if a > b then max64 := a else max64 := b; end;
function min(a,b : longint) : longint; begin if a > b then min := b else min := a; end;
function max(a,b : longint) : longint; begin if a > b then max := a else max := b; end;
function gcd(a,b : longint) : longint; var t : longint; begin if b = 0 then exit(a); gcd := gcd(b, a mod b); end;

begin
     readln(n,m);

     if (m < n-1)
     then writeln('Impossible')
     else begin
               cnt := 0;
               for i := 1 to n do
               begin
                    for j := i+1 to n do
                    begin
                         if gcd(i,j) = 1
                         then begin
                                   inc(cnt);
                                   edge[cnt,1] := i;
                                   edge[cnt,2] := j;
                              end;
                         if cnt = m
                         then begin
                                   writeln('Possible');
                                   for k := 1 to cnt do
                                       writeln(edge[k,1],' ',edge[k,2]);
                                   halt;
                              end;
                    end;
               end;
               writeln('Impossible');
          end;
end.