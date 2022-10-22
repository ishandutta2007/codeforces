var n : int64;

begin
     readln(n);
     if (n mod 2 = 0)
     then writeln(n div 2)
     else writeln(n div 2 - n);
end.