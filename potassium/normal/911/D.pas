program InversionCounting;

var n,m                   : longint;
    i,j                   : longint;
    a                     : array[1..1500] of longint;
    l,r                   : longint;
    cnt                   : longint;

begin
     readln(n);
     for i := 1 to n do
         read(a[i]);

     cnt := 0;

     for i := 1 to n-1 do
         for j := i+1 to n do
             if a[i] > a[j]
             then inc(cnt);

     cnt := cnt mod 2;

     readln(m);
     for i := 1 to m do
     begin
          readln(l,r);

          cnt := cnt + ((r-l)*(r-l+1)) div 2;
          cnt := cnt mod 2;

          if (cnt = 1)
          then writeln('odd')
          else writeln('even');
     end;
end.