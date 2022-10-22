program Codeforces;

var
    i,j            : longint;

    n,k            : longint;
    a              : array[0..5000] of longint;

    value          : double;
    max            : double;

begin
     readln(n,k);

     a[0] := 0;

     for i := 1 to n do
     begin
          read(a[i]);
          inc(a[i],a[i-1]);
     end;

     readln;

     max := 0;

     for i := k to n do
         for j := 1 to n-i+1 do
         begin
              value := (a[j+i-1] - a[j-1]) / i;
              if value > max
              then max := value;
         end;

     writeln(max:0:12);

     readln;
end.