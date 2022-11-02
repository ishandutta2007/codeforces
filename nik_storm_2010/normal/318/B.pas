var
  s:ansistring; d,i:longint; ans,k:int64;


begin

  readln(s); d:=length(s);
  for i:=1 to d do
  begin
    if (d-i+1>=5) and (s[i]='h') and (s[i+1]='e') and (s[i+2]='a') and (s[i+3]='v') and (s[i+4]='y') then inc(k);
    if (d-i+1>=5) and (s[i]='m') and (s[i+1]='e') and (s[i+2]='t') and (s[i+3]='a') and (s[i+4]='l') then ans:=ans+k;
  end;
  writeln(ans);

end.