var
    s1,s2:ansistring; d1,d2,i:longint; z1,z2:boolean;


begin

  readln(s1); d1:=length(s1); z1:=true;
  readln(s2); d2:=length(s2); z2:=true;
  for i:=1 to d1 do if s1[i]='1' then begin z1:=false; break; end;
  for i:=1 to d2 do if s2[i]='1' then begin z2:=false; break; end;
  if (d1<>d2) or ((z1=false)and(z2=true)) or ((z1=true)and(z2=false)) then writeln('NO') else writeln('YES');

end.