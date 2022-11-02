uses math;
var
  ans,cnt,k1,k0,d,i:longint; s:ansistring;


begin
  readln(s); d:=length(s);
  ans:=0; i:=1;
  while (i<=d) do
  begin
    if (s[i]='0') then begin inc(i); continue; end;
    k1:=0; k0:=0;
    while i<=d do
    begin
      if (s[i]='1') then inc(k1) else
      if (i=d) or (s[i+1]='0') then break else inc(k0);
      inc(i);
    end;
    ans:=ans+min(k1,2+k0);
  end;
  writeln(ans);
end.