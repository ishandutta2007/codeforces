var
    kol:array[1..1000] of longint; max,nom,n,i,c:longint;


begin

  readln(n); max:=0;
  for i:=1 to n do
    begin
      read(c); inc(kol[c]);
      if kol[c]>max then begin max:=kol[c]; nom:=c; end;
    end;
  if max>(n+1) div 2 then writeln('NO') else writeln('YES');

end.