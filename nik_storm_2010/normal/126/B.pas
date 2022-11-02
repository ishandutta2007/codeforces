uses math;
var
  z,cnt:array[0..1000000] of longint; s:ansistring; d,i:longint;


procedure zetfunction;
var i,l,r:longint;
begin
  l:=0; r:=0;
  for i:=2 to d do
  begin
    if i<=r then z[i]:=min(r-i+1,z[i-l+1]);
    while (i+z[i]<=d) and (s[z[i]+1]=s[i+z[i]]) do inc(z[i]);
    if i+z[i]-1>r then begin l:=i; r:=i+z[i]-1; end;
    inc(cnt[z[i]]);
  end;
end;


begin

  readln(s); d:=length(s);
  zetfunction;
  for i:=d downto 1 do
    if (cnt[i]>=2) and (z[d-i+1]=i) then
    begin
      writeln(copy(s,1,i));
      halt;
    end
    else cnt[i-1]:=cnt[i-1]+cnt[i];
  writeln('Just a legend');

end.