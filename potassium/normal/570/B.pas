var n,m : longint;

begin
     readln(n,m);
     if (n = 1) AND (m = 1)
     then writeln(1)
     else if (m-1) >= (n-m)
          then writeln(m-1)
          else writeln(m+1);
end.