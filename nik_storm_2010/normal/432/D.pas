uses
  math;
const
  lim=200000;
var
  z,cnt:array[0..lim] of longint;
  ans,sum,d,l,r,k,i,j:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  for i:=2 to d do
  begin
    if (i<=r) then z[i]:=min(r-i+1,z[i-l+1]);
    while (z[i]+i<=d) and (s[z[i]+1]=s[z[i]+i]) do inc(z[i]);
    if (i+z[i]-1>r) then begin l:=i; r:=i+z[i]-1; end;
  end;
  z[1]:=d;
  for i:=1 to d do inc(cnt[z[i]]);
  ans:=0; sum:=0;
  for i:=1 to lim do sum:=sum+cnt[i];
  for i:=1 to d do
  begin
    j:=d-i+1;
    if (z[j]<>i) then continue else inc(ans);
  end;
  writeln(ans);
  for i:=1 to d do
  begin
    j:=d-i+1;
    if (z[j]=i) then writeln(i,' ',sum);
    sum:=sum-cnt[i];
  end;
end.