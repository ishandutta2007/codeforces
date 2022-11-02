var
  st:array[1..100000] of char;
  s:ansistring;
  d,i,k:longint;

begin
  readln(s); d:=length(s);
  for i:=1 to d do
    if (k>0) and (st[k]=s[i]) then dec(k) else
    begin
      inc(k);
      st[k]:=s[i];
    end;
  if (k=0) then writeln('Yes') else writeln('No');
end.