program Team;

var cnt      : longint;
    i,n      : longint;
    a,b,c    : longint;

begin
     readln(n);

     for i := 1 to n do
     begin
          readln(a,b,c);

          if a+b+c >= 2
          then inc(cnt);
     end;

     writeln(cnt);
end.