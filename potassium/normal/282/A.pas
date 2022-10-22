program Team;

var cnt      : longint;
    i,n      : longint;
    c        : char;

begin
     readln(n);

     for i := 1 to n do
     begin
          readln(c,c);

          if c = '+'
          then inc(cnt)
          else dec(cnt);
     end;

     writeln(cnt);
end.