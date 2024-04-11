const mo=1000000007;
var
  s,t:ansistring;
  ans:int64;
  n,m:longint;
  next:array [1..100000] of longint;
  f,sum,h:array [0..100000] of longint;
procedure init;
var
  i,j:longint;
  o:int64;
begin
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  j:=0;
  for i:=2 to m do
  begin
    while (j<>0) and (t[i]<>t[j+1]) do j:=next[j];
    if t[i]=t[j+1] then inc(j);
    next[i]:=j;
  end;
  j:=0;
  o:=0;
  f[0]:=0;
  sum[0]:=1;
  h[0]:=1;
  for i:=1 to n do
  begin
    while (j<>0) and (s[i]<>t[j+1]) do j:=next[j];
    if s[i]=t[j+1] then inc(j);
    if j=m then
    begin
      f[i]:=h[i-m];
      if o<>0 then ans:=(ans+f[o]*(i-o)) mod mo;
      o:=i;
    end
    else f[i]:=f[i-1];
    sum[i]:=(sum[i-1]+f[i]) mod mo;
    h[i]:=(h[i-1]+sum[i]) mod mo;
  end;
  if o<>0 then ans:=(ans+f[o]*(n-o+1)) mod mo;
  writeln(ans);
end;
begin
  init;
end.