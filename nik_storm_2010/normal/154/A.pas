uses math;
var
  g:array['a'..'z','a'..'z'] of byte; s:ansistring;
  ans,i,j,k,k1,k2,d:longint; c1,c2:char;


begin
  readln(s); readln(k); d:=length(s);
  for i:=1 to k do begin readln(c1,c2); g[c1,c2]:=1; g[c2,c1]:=1; end;
  i:=2; k1:=1;
  while i<=d do
  begin
    if g[s[i],s[i-1]]=1 then
    begin
      j:=i+1; k2:=1;
      while (j<=d) do
      begin
        if s[j]=s[i-1] then inc(k1) else
        if s[j]=s[i] then inc(k2) else break;
        inc(j);
      end;
      ans:=ans+min(k1,k2); i:=j; k1:=1;
    end
    else
    begin
      if s[i]=s[i-1] then inc(k1) else k1:=1;
      inc(i);
    end;
  end;
  writeln(ans);
end.