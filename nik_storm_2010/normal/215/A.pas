var
    a,b:array[1..50] of longint; c:extended;
     n,m,i,j,tek,kol:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
    readln;
  readln(m); for i:=1 to m do read(b[i]);

  for i:=1 to n do
    for j:=1 to m do
      begin
        c:=b[j]/a[i];
        if frac(c)=0 then
          begin
            if trunc(c)>tek then
              begin
                tek:=trunc(c);
                kol:=1;
              end
                else
              begin
                if trunc(c)=tek then inc(kol);
              end;
          end;
      end;
  writeln(kol);

end.