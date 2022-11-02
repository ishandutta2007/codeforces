var
    f:array[0..100000] of longint; d,i,l,r,m:longint; s:ansistring;


begin

  readln(s); d:=length(s);
  for i:=1 to d-1 do
  begin
    f[i]:=f[i-1];
    if s[i]=s[i+1] then inc(f[i]);
  end;
  readln(m);
  for i:=1 to m do
    begin
      readln(l,r);
      writeln(f[r-1]-f[l-1]);
    end;

end.