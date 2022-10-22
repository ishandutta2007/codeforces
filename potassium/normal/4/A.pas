program Watermelon;

var w   : integer;

begin
     readln(w);

     if (w mod 2 = 0) AND (w > 2)
     then writeln('YES')
     else writeln('NO');
end.