program ThreeGarlands;

var k                 : array[1..3] of longint;
    cnt               : array[1..4] of longint;
    i                 : longint;

begin
     readln(k[1],k[2],k[3]);

     for i := 2 to 3 do
         cnt[i] := 0;

     for i := 1 to 3 do
         if k[i] = 1
         then inc(cnt[1]);

     for i := 1 to 3 do
         if k[i] = 2
         then inc(cnt[2]);

     for i := 1 to 3 do
         if k[i] = 3
         then inc(cnt[3]);

     for i := 1 to 3 do
         if k[i] = 4
         then inc(cnt[4]);

     if (cnt[1] >= 1) OR(cnt[2] >= 2) OR (cnt[3] >= 3) OR ((cnt[2] = 1) AND (cnt[4] = 2))
     then writeln('YES')
     else writeln('NO');
end.