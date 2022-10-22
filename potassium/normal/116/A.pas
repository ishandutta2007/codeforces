program Tram;

uses math;

var n,i      : longint;
    cnt,ans  : longint;
    a,b      : array[1..1000] of longint;

begin
     readln(n);

     cnt := 0;
     ans := 0;

     for i := 1 to n do
     begin
          readln(a[i],b[i]);

          cnt := cnt - a[i] + b[i];
          ans := max(ans,cnt);
     end;

     writeln(ans);
end.