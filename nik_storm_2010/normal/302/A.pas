var
    kol1,kol2,n,m,i,c,l,r:longint;


begin

  readln(n,m); kol1:=0; kol2:=0;
  for i:=1 to n do
    begin
      read(c);
      if c=1 then inc(kol1) else inc(kol2);
    end;
  for i:=1 to m do
    begin
      readln(l,r);
      if ((r-l+1) mod 2=0) and (kol1>=(r-l+1) div 2) and (kol2>=(r-l+1) div 2) then writeln(1) else writeln(0);
    end;

end.