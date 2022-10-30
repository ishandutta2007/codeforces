uses math;
var
    f:array[0..1001,0..1001] of longint; a:array[97..122] of longint;
      kolc,koln,tek,d,i,j:longint; s:ansistring;


begin

  readln(s); d:=length(s); kolc:=0; koln:=0;
  for i:=1 to d do inc(a[ord(s[i])]);
  for i:=97 to 122 do
    if a[i]<>0 then
    begin
      if a[i] mod 2=0 then inc(kolc) else inc(koln);
    end;
  for i:=0 to d do
    for j:=0 to d do
    if (j=0) or (j=1) then f[i,j]:=1 else
    begin
      if i=0 then f[i,j]:=j mod 2 else
      begin
        tek:=f[i-1,j+1]; tek:=min(tek,f[i,j-1]);
        if tek=1 then f[i,j]:=0 else f[i,j]:=1;
      end;
    end;
  if f[kolc,koln]=1 then writeln('First') else writeln('Second');

end.