uses math;
var
  f:array['a'..'z','a'..'z'] of longint; ans,d,n,i:longint; s:string; c:char;


begin
  readln(n); ans:=0;
  for i:=1 to n do
  begin
    readln(s); d:=length(s);
    for c:='a' to 'z' do
      if (f[c,s[1]]<>0) then
      begin
        if (s[d]=c) then ans:=max(ans,f[c,s[1]]+d);
        f[c,s[d]]:=max(f[c,s[d]],f[c,s[1]]+d);
      end;
    if (s[1]=s[d]) then ans:=max(ans,d);
    f[s[1],s[d]]:=max(f[s[1],s[d]],d);
  end;
  writeln(ans);
end.