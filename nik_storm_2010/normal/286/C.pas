var
    a,s:array[0..1000000] of longint; n,q,i,x,k:longint;


begin

  readln(n); for i:=1 to n do read(a[i]); readln;
  read(q);
  for i:=1 to q do
    begin
      read(x); a[x]:=-a[x];
    end;
  k:=0;
  for i:=n downto 1 do
    if (k=0) or (a[i]<>s[k]) then
    begin
      inc(k); s[k]:=abs(a[i]); a[i]:=-s[k];
    end
    else dec(k);
  if k<>0 then writeln('NO') else
    begin
      writeln('YES');
      for i:=1 to n do write(a[i],' ');
    end;

end.