var
  s:ansistring;
  d,i,ans,j:longint;
  have:boolean;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do
  begin
    have:=false;
    for j:=i+3 to d do
    begin
      if (s[j-3]='b') and (s[j-2]='e') and (s[j-1]='a') and (s[j]='r') then have:=true;
      if (have) then inc(ans);
    end;
  end;
  writeln(ans);
end.