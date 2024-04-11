var
    k11,k10,k01,k00,k1,k2,n,i:longint; s,t:ansistring;


begin

  readln(n); readln(s); readln(t);
  k11:=0; k10:=0; k01:=0; k00:=0;
  for i:=1 to 2*n do
    begin
      if (s[i]='1') and (t[i]='1') then inc(k11);
      if (s[i]='1') and (t[i]='0') then inc(k10);
      if (s[i]='0') and (t[i]='1') then inc(k01);
      if (s[i]='0') and (t[i]='0') then inc(k00);
    end;
  k1:=0; k2:=0;
  for i:=1 to n do
    begin
      if (k11<>0) then begin inc(k1); dec(k11); end else
      if (k10<>0) then begin inc(k1); dec(k10); end else
      if (k01<>0) then dec(k01) else dec(k00);
      if (k11<>0) then begin inc(k2); dec(k11); end else
      if (k01<>0) then begin inc(k2); dec(k01); end else
      if (k10<>0) then dec(k10) else dec(k00);
    end;
  if k1=k2 then writeln('Draw') else if k1>k2 then writeln('First') else writeln('Second');

end.