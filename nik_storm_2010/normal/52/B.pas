var
  a:array[1..1000,1..1000] of char; v,g:array[1..1000] of int64;
  n,m,i,j:longint; ans:int64;


begin

  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  fillchar(g,sizeof(g),0); fillchar(v,sizeof(v),0);
  for i:=1 to n do for j:=1 to m do
    if a[i,j]='*' then
    begin
      ans:=ans+g[i]*v[j];
      inc(g[i]); inc(v[j]);
    end;
  fillchar(g,sizeof(g),0); fillchar(v,sizeof(v),0);
  for i:=1 to n do for j:=m downto 1 do
    if a[i,j]='*' then
    begin
      ans:=ans+g[i]*v[j];
      inc(g[i]); inc(v[j]);
    end;
  fillchar(g,sizeof(g),0); fillchar(v,sizeof(v),0);
  for i:=n downto 1 do for j:=1 to m do
    if a[i,j]='*' then
    begin
      ans:=ans+g[i]*v[j];
      inc(g[i]); inc(v[j]);
    end;
  fillchar(g,sizeof(g),0); fillchar(v,sizeof(v),0);
  for i:=n downto 1 do for j:=m downto 1 do
    if a[i,j]='*' then
    begin
      ans:=ans+g[i]*v[j];
      inc(g[i]); inc(v[j]);
    end;
  writeln(ans);

end.