var
  n,r,t:extended;

begin

  readln(n,r,t);
  if t>r then writeln('NO') else
    begin
      if (n=1) or (n=2) then
        begin
          if (r/n)>=t then writeln('YES') else writeln('NO');
        end
          else
        begin
          if (r-t)*sin(pi/n)>=t then writeln('YES') else writeln('NO');
        end
    end;

end.