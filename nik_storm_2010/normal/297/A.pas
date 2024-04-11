var
    a,b:ansistring; n,i,ka,kb:longint;


begin

  readln(a); readln(b); ka:=0; kb:=0;
  for i:=1 to length(a) do if a[i]='1' then inc(ka);
  for i:=1 to length(b) do if b[i]='1' then inc(kb);
  if (ka>=kb) or ((ka mod 2=1) and (kb-ka=1)) then writeln('YES') else writeln('NO');

end.