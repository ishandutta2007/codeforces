var
  s,x,a1,a2:ansistring;
  k1,k2,i,nom,d,d2:longint;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do if (s[i]='|') then nom:=i;
  k1:=nom-1;
  k2:=d-nom;
  readln(x);
  d2:=length(x);
  if (k1+k2+d2) mod 2<>0 then begin writeln('Impossible'); halt; end;
  a1:=''; a2:='';
  while (d2<>0) do
  begin
    if (k1<k2) then
    begin
      a1:=a1+x[d2];
      inc(k1);
    end
    else
    begin
      a2:=a2+x[d2];
      inc(k2);
    end;
    dec(d2);
  end;
  if (k1<>k2) then begin writeln('Impossible'); halt; end;
  for i:=1 to d do
  begin
    if (s[i]='|') then write(a1);
    write(s[i]);
  end;
  write(a2);
end.