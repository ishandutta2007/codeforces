const
  lim=300010;
var
  a:array['a'..'z',0..lim] of longint;
  used:array['a'..'z'] of boolean;
  res:array[1..30] of int64;
  ans,d,i,k:longint;
  s:ansistring;
  l,j:int64;
  c,o:char;

begin
  readln(s);
  d:=length(s);
  for c:='a' to 'z' do a[c,d]:=maxlongint;
  for i:=d-1 downto 0 do
  begin
    for c:='a' to 'z' do a[c,i]:=a[c,i+1];
    a[s[i+1],i]:=i+1;
  end;
  ans:=0;
  for c:='a' to 'z' do if (a[c,0]<>maxlongint) then inc(ans);
  for i:=1 to d do
  begin
    fillchar(used,sizeof(used),false);
    used[s[i]]:=true;
    j:=i;
    k:=1;
    while (j<=d) do
    begin
      l:=d+1;
      for o:='a' to 'z' do
      begin
        if (used[o]) or (a[o,j]=maxlongint) then continue;
        if (l>a[o,j]) then begin l:=a[o,j]; c:=o; end;
      end;
      used[c]:=true;
      res[k]:=res[k]+l-j;
      j:=l;
      inc(k);
    end;
  end;
  writeln(ans);
  for i:=1 to ans do writeln(res[i]);
end.