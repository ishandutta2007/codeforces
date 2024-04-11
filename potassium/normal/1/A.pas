program TheatreSquare;

var n,m,a : int64;

begin
     readln(n,m,a);

     writeln(((n+a-1) div a) * ((m+a-1) div a));
     readln;
end.