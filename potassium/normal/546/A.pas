var k,n,w : longint;

begin
     readln(k,n,w);

     if (w*w+w) div 2 * k <= n
     then writeln(0)
     else writeln((w*w+w) div 2 * k - n);
end.