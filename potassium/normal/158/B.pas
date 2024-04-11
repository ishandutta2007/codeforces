program Taxi;

uses math;

var n,i,x    : longint;
    a        : array[1..4] of longint;
    cnt      : longint;

begin
     readln(n);

     for i := 1 to n do
     begin
          read(x);
          inc(a[x]);
     end;

     readln;

     cnt := a[4] + a[3];

     a[1] := max(0,a[1]-a[3]);

     if (a[2] mod 2 = 1)
     then begin
               dec(a[2]);
               dec(a[1],2);
               inc(cnt);
          end;

     if (a[1] mod 4 > 0)
     then cnt := cnt + 1;

     cnt := cnt + + a[2] div 2 + a[1] div 4;

     writeln(cnt);
end.