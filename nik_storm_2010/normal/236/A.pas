var
    a:array[97..122] of longint; kol,d,i:longint; s:string;


begin

  readln(s); d:=length(s); kol:=0;
  for i:=1 to d do
    begin
      if a[ord(s[i])]=0 then inc(kol);
      inc(a[ord(s[i])]);
    end;
  if kol mod 2=1 then writeln('IGNORE HIM!') else writeln('CHAT WITH HER!');

end.